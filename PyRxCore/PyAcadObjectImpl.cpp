#include "stdafx.h"
#include "PyAcadObjectImpl.h"
#include "PyAcadDbObjectImpl.h"

//------------------------------------------------------------------------------------
// Helpers
AcDbObjectIdArray VariantToAcDbObjectIdArray(VARIANT& var)
{
    ULONG pcElem = 0;
    AcDbObjectIdArray ids;
    LONGLONG* prgn = nullptr;
    if (VariantToInt64ArrayAlloc(var, &prgn, &pcElem) == S_OK) //TODO: Test
    {
        AcDbObjectId id;
        std::span<LONGLONG>data(prgn, pcElem);
        for (auto item : data)
            ids.append(id.setFromOldId(item));
        CoTaskMemFree(prgn);
    }
    return ids;
}

void AcDbObjectIdArrayToVariant(VARIANT& var, const AcDbObjectIdArray& ids)
{
    std::vector<LONGLONG> data;
    data.reserve(ids.length());
    for (const AcDbObjectId& id : ids)
        data.push_back(id.asOldId());
    InitVariantFromInt64Array(data.data(), data.size(), &var);
}

//------------------------------------------------------------------------------------
//PyIAcadAcCmColorImpl
PyIAcadAcCmColorImpl::PyIAcadAcCmColorImpl(IAcadAcCmColor* ptr)
    : m_pimpl(ptr)
{
}

void PyIAcadAcCmColorImpl::SetEntityColor(long val)
{
    PyThrowBadHr(impObj()->put_EntityColor(val));
}

long PyIAcadAcCmColorImpl::GetEntityColor() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_EntityColor(&val));
    return val;
}

CString PyIAcadAcCmColorImpl::GetColorName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ColorName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyIAcadAcCmColorImpl::GetBookName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_BookName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadAcCmColorImpl::SetNames(const CString& colorName, const CString& bookName)
{
    _bstr_t bstrcolorName{ colorName };
    _bstr_t bstrbookName{ bookName };
    PyThrowBadHr(impObj()->SetNames(bstrcolorName, bstrbookName));
}

void PyIAcadAcCmColorImpl::Delete()
{
    PyThrowBadHr(impObj()->Delete());
}

long PyIAcadAcCmColorImpl::GetRed() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Red(&val));
    return val;
}

long PyIAcadAcCmColorImpl::GetGreen() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Green(&val));
    return val;
}

long PyIAcadAcCmColorImpl::GetBlue() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Blue(&val));
    return val;
}

void PyIAcadAcCmColorImpl::SetRGB(long Red, long Green, long Blue)
{
    PyThrowBadHr(impObj()->SetRGB(Red, Green, Blue));
}

void PyIAcadAcCmColorImpl::SetColorMethod(PyAcColorMethod flags)
{
    AcColorMethod _flags = (AcColorMethod)flags;
    PyThrowBadHr(impObj()->put_ColorMethod(_flags));
}

PyAcColor PyIAcadAcCmColorImpl::GetColorIndex() const
{
    AcColor val = (AcColor)PyAcColor::pyacByBlock;
    PyThrowBadHr(impObj()->get_ColorIndex(&val));
    return (PyAcColor)val;
}

void PyIAcadAcCmColorImpl::SetColorIndex(PyAcColor val)
{
    PyThrowBadHr(impObj()->put_ColorIndex(AcColor(val)));
}

void PyIAcadAcCmColorImpl::SetColorBookColor(const CString& colorName, const CString& bookName)
{
    _bstr_t bstrcolorName{ colorName };
    _bstr_t bstrbookName{ bookName };
    PyThrowBadHr(impObj()->SetColorBookColor(bstrcolorName, bstrbookName));
}

PyAcColorMethod PyIAcadAcCmColorImpl::GetColorMethod() const
{

    AcColorMethod val = (AcColorMethod)PyAcColorMethod::pyacColorMethodByLayer;
    PyThrowBadHr(impObj()->get_ColorMethod(&val));
    return (PyAcColorMethod)val;
}

IAcadAcCmColor* PyIAcadAcCmColorImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadAcCmColor*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadEntityImpl
PyIAcadHyperlinkImpl::PyIAcadHyperlinkImpl(IAcadHyperlink* ptr)
    : m_pimpl(ptr)
{
}

CString PyIAcadHyperlinkImpl::GetURL() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_URL(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadHyperlinkImpl::SetURL(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_URL(bstrval));
}

CString PyIAcadHyperlinkImpl::GetURLDescription() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_URLDescription(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadHyperlinkImpl::SetURLDescription(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_URLDescription(bstrval));
}

void PyIAcadHyperlinkImpl::Delete()
{
    PyThrowBadHr(impObj()->Delete());
}

CString PyIAcadHyperlinkImpl::GetURLNamedLocation() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_URLNamedLocation(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadHyperlinkImpl::SetURLNamedLocation(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_URLNamedLocation(bstrval));
}

IAcadHyperlink* PyIAcadHyperlinkImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadHyperlink*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadHyperlinksImpl
PyIAcadHyperlinksImpl::PyIAcadHyperlinksImpl(IAcadHyperlinks* ptr)
    : m_pimpl(ptr)
{
}

PyIAcadHyperlinkPtr PyIAcadHyperlinksImpl::GetItem(long val)
{
    IAcadHyperlink* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return std::make_unique<PyIAcadHyperlinkImpl>(ptr);
}

long PyIAcadHyperlinksImpl::GetCount() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Count(&val));
    return val;
}

PyIAcadHyperlinkPtr PyIAcadHyperlinksImpl::Add(const CString& name, const CString& description, const CString& namedLocation)
{
    IAcadHyperlink* ptr = nullptr;
    _bstr_t bstrname{ name };
    _variant_t bstrdescription{ static_cast<const wchar_t*>(description) };
    _variant_t bstrnamedLocation{ static_cast<const wchar_t*>(namedLocation) };
    PyThrowBadHr(impObj()->Add(bstrname, bstrdescription, bstrnamedLocation, &ptr));
    return std::make_unique<PyIAcadHyperlinkImpl>(ptr);
}

IAcadHyperlinks* PyIAcadHyperlinksImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadHyperlinks*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//IAcadSectionTypeSettingsImpl
PyIAcadSectionTypeSettingsImpl::PyIAcadSectionTypeSettingsImpl(IAcadSectionTypeSettings* ptr)
    : m_pimpl(ptr)
{
}

PyAcSectionGeneration PyIAcadSectionTypeSettingsImpl::GetGenerationOptions() const
{
    AcSectionGeneration val = (AcSectionGeneration)PyAcSectionGeneration::pyacSectionGenerationDestinationFile;
    PyThrowBadHr(impObj()->get_GenerationOptions(&val));
    return (PyAcSectionGeneration)val;
}

void PyIAcadSectionTypeSettingsImpl::SetGenerationOptions(PyAcSectionGeneration val)
{
    AcSectionGeneration _val = (AcSectionGeneration)val;
    PyThrowBadHr(impObj()->put_GenerationOptions(_val));
}

AcDbObjectIdArray PyIAcadSectionTypeSettingsImpl::GetSourceObjects() const
{
    VARIANT vtids;
    VariantInit(&vtids);
    PyThrowBadHr(impObj()->get_SourceObjects(&vtids));
    return VariantToAcDbObjectIdArray(vtids);
}

void PyIAcadSectionTypeSettingsImpl::SetSourceObjects(const AcDbObjectIdArray& ids)
{
    _variant_t vtids;
    AcDbObjectIdArrayToVariant(vtids.GetVARIANT(), ids);
    PyThrowBadHr(impObj()->put_SourceObjects(vtids));
}

PyIAcadBlockPtr PyIAcadSectionTypeSettingsImpl::GetDestinationBlock()
{
    _variant_t vt;
    IDispatch* dsp = nullptr;
    PyThrowBadHr(impObj()->get_DestinationBlock(&vt.GetVARIANT()));
    return std::make_unique<PyIAcadBlockImpl>(static_cast<IAcadBlock*>(vt.pdispVal) );
}

void PyIAcadSectionTypeSettingsImpl::SetDestinationBlock(const PyIAcadBlockImpl& val)
{
    _variant_t vt{ static_cast<IDispatch*>(val.impObj()) };
    PyThrowBadHr(impObj()->put_DestinationBlock(vt));
}

CString PyIAcadSectionTypeSettingsImpl::GetDestinationFile() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DestinationFile(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadSectionTypeSettingsImpl::SetDestinationFile(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_DestinationFile(bstrVal));
}

PyIAcadAcCmColorPtr PyIAcadSectionTypeSettingsImpl::GetIntersectionBoundaryColor() const
{
    IAcadAcCmColor* ptr = nullptr;
    PyThrowBadHr(impObj()->get_IntersectionBoundaryColor(&ptr));
    return std::make_unique<PyIAcadAcCmColorImpl>(ptr);
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionBoundaryColor(const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->put_IntersectionBoundaryColor(val.impObj()));
}

CString PyIAcadSectionTypeSettingsImpl::GetIntersectionBoundaryLayer() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_IntersectionBoundaryLayer(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionBoundaryLayer(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_IntersectionBoundaryLayer(bstrVal));
}

CString PyIAcadSectionTypeSettingsImpl::GetIntersectionBoundaryLinetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_IntersectionBoundaryLinetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionBoundaryLinetype(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_IntersectionBoundaryLinetype(bstrVal));
}

double PyIAcadSectionTypeSettingsImpl::GetIntersectionBoundaryLinetypeScale() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_IntersectionBoundaryLinetypeScale(&rtVal));
    return rtVal;
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionBoundaryLinetypeScale(double val)
{
    PyThrowBadHr(impObj()->put_IntersectionBoundaryLinetypeScale(val));
}

CString PyIAcadSectionTypeSettingsImpl::GetIntersectionBoundaryPlotStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_IntersectionBoundaryPlotStyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionBoundaryPlotStyleName(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_IntersectionBoundaryPlotStyleName(bstrVal));
}

PyAcLineWeight PyIAcadSectionTypeSettingsImpl::GetIntersectionBoundaryLineweight() const
{
    AcLineWeight val = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_IntersectionBoundaryLineweight(&val));
    return (PyAcLineWeight)val;
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionBoundaryLineweight(PyAcLineWeight val)
{
    PyThrowBadHr(impObj()->put_IntersectionBoundaryLineweight((AcLineWeight)val));
}

bool PyIAcadSectionTypeSettingsImpl::GetIntersectionBoundaryDivisionLines() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_IntersectionBoundaryDivisionLines(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionBoundaryDivisionLines(bool val) const
{
    PyThrowBadHr(impObj()->put_IntersectionBoundaryDivisionLines(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadSectionTypeSettingsImpl::GetIntersectionFillVisible() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_IntersectionFillVisible(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionFillVisible(bool val) const
{
    PyThrowBadHr(impObj()->put_IntersectionFillVisible(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcPatternType PyIAcadSectionTypeSettingsImpl::GetIntersectionFillHatchPatternType() const
{
    AcPatternType val = (AcPatternType)PyAcPatternType::pyacHatchPatternTypeUserDefined;
    PyThrowBadHr(impObj()->get_IntersectionFillHatchPatternType(&val));
    return (PyAcPatternType)val;
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionFillHatchPatternType(PyAcPatternType val)
{
    PyThrowBadHr(impObj()->put_IntersectionFillHatchPatternType((AcPatternType)val));
}

CString PyIAcadSectionTypeSettingsImpl::GetIntersectionFillHatchPatternName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_IntersectionFillHatchPatternName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionFillHatchPatternName(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_IntersectionFillHatchPatternName(bstrVal));
}

double PyIAcadSectionTypeSettingsImpl::GetIntersectionFillHatchAngle() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_IntersectionFillHatchAngle(&rtVal));
    return rtVal;
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionFillHatchAngle(double val)
{
    PyThrowBadHr(impObj()->put_IntersectionFillHatchAngle(val));
}

double PyIAcadSectionTypeSettingsImpl::GetIntersectionFillHatchScale() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_IntersectionFillHatchScale(&rtVal));
    return rtVal;
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionFillHatchScale(double val)
{
    PyThrowBadHr(impObj()->put_IntersectionFillHatchScale(val));
}

double PyIAcadSectionTypeSettingsImpl::GetIntersectionFillHatchSpacing() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_IntersectionFillHatchSpacing(&rtVal));
    return rtVal;
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionFillHatchSpacing(double val)
{
    PyThrowBadHr(impObj()->put_IntersectionFillHatchSpacing(val));
}

PyIAcadAcCmColorPtr PyIAcadSectionTypeSettingsImpl::GetIntersectionFillColor() const
{
    IAcadAcCmColor* ptr = nullptr;
    PyThrowBadHr(impObj()->get_IntersectionFillColor(&ptr));
    return std::make_unique<PyIAcadAcCmColorImpl>(ptr);
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionFillColor(const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->put_IntersectionFillColor(val.impObj()));
}

CString PyIAcadSectionTypeSettingsImpl::GetIntersectionFillLayer() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_IntersectionFillLayer(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionFillLayer(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_IntersectionFillLayer(bstrVal));
}

CString PyIAcadSectionTypeSettingsImpl::GetIntersectionFillLinetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_IntersectionFillLinetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionFillLinetype(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_IntersectionFillLinetype(bstrVal));
}

double PyIAcadSectionTypeSettingsImpl::GetIntersectionFillLinetypeScale() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_IntersectionFillLinetypeScale(&rtVal));
    return rtVal;
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionFillLinetypeScale(double val)
{
    PyThrowBadHr(impObj()->put_IntersectionFillLinetypeScale(val));
}

void PyIAcadSectionTypeSettingsImpl::SetIntersectionFillPlotStyleName(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_IntersectionFillPlotStyleName(bstrVal));
}

CString PyIAcadSectionTypeSettingsImpl::GetIntersectionFillPlotStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_IntersectionFillPlotStyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

IAcadSectionTypeSettings* PyIAcadSectionTypeSettingsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSectionTypeSettings*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDatabasePreferencesImpl
PyIAcadDatabasePreferencesImpl::PyIAcadDatabasePreferencesImpl(IAcadDatabasePreferences* ptr)
    : m_pimpl(ptr)
{
}

bool PyIAcadDatabasePreferencesImpl::GetSolidFill() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SolidFill(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDatabasePreferencesImpl::SetSolidFill(bool val) const
{
    PyThrowBadHr(impObj()->put_SolidFill(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDatabasePreferencesImpl::GetXRefEdit() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_XRefEdit(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDatabasePreferencesImpl::SetXRefEdit(bool val) const
{
    PyThrowBadHr(impObj()->put_XRefEdit(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDatabasePreferencesImpl::GetXRefLayerVisibility() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_XRefLayerVisibility(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDatabasePreferencesImpl::SetXRefLayerVisibility(bool val) const
{
    PyThrowBadHr(impObj()->put_XRefLayerVisibility(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDatabasePreferencesImpl::GetOLELaunch() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_OLELaunch(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDatabasePreferencesImpl::SetOLELaunch(bool val) const
{
    PyThrowBadHr(impObj()->put_OLELaunch(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDatabasePreferencesImpl::GetAllowLongSymbolNames() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AllowLongSymbolNames(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDatabasePreferencesImpl::SetAllowLongSymbolNames(bool val) const
{
    PyThrowBadHr(impObj()->put_AllowLongSymbolNames(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDatabasePreferencesImpl::GetObjectSortBySelection() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ObjectSortBySelection(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDatabasePreferencesImpl::SetObjectSortBySelection(bool val) const
{
    PyThrowBadHr(impObj()->put_ObjectSortBySelection(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDatabasePreferencesImpl::GetObjectSortBySnap() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ObjectSortBySnap(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDatabasePreferencesImpl::SetObjectSortBySnap(bool val) const
{
    PyThrowBadHr(impObj()->put_ObjectSortBySnap(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDatabasePreferencesImpl::GetObjectSortByRedraws() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ObjectSortByRedraws(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDatabasePreferencesImpl::SetObjectSortByRedraws(bool val) const
{
    PyThrowBadHr(impObj()->put_ObjectSortByRedraws(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDatabasePreferencesImpl::GetObjectSortByRegens() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ObjectSortByRegens(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDatabasePreferencesImpl::SetObjectSortByRegens(bool val) const
{
    PyThrowBadHr(impObj()->put_ObjectSortByRegens(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDatabasePreferencesImpl::GetObjectSortByPlotting() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ObjectSortByPlotting(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDatabasePreferencesImpl::SetObjectSortByPlotting(bool val) const
{
    PyThrowBadHr(impObj()->put_ObjectSortByPlotting(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDatabasePreferencesImpl::GetObjectSortByPSOutput() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ObjectSortByPSOutput(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDatabasePreferencesImpl::SetObjectSortByPSOutput(bool val) const
{
    PyThrowBadHr(impObj()->put_ObjectSortByPSOutput(val ? VARIANT_TRUE : VARIANT_FALSE));
}

void PyIAcadDatabasePreferencesImpl::SetContourLinesPerSurface(long val) const
{
    PyThrowBadHr(impObj()->put_ContourLinesPerSurface(val));
}

long PyIAcadDatabasePreferencesImpl::GetContourLinesPerSurface() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_ContourLinesPerSurface(&rtVal));
    return rtVal;
}

void PyIAcadDatabasePreferencesImpl::SetDisplaySilhouette(bool val) const
{
    PyThrowBadHr(impObj()->put_DisplaySilhouette(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDatabasePreferencesImpl::GetDisplaySilhouette() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DisplaySilhouette(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDatabasePreferencesImpl::SetMaxActiveViewports(long val) const
{
    PyThrowBadHr(impObj()->put_MaxActiveViewports(val));
}

long PyIAcadDatabasePreferencesImpl::GetMaxActiveViewports() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_MaxActiveViewports(&rtVal));
    return rtVal;
}

void PyIAcadDatabasePreferencesImpl::SetRenderSmoothness(double val) const
{
    PyThrowBadHr(impObj()->put_RenderSmoothness(val));
}

double PyIAcadDatabasePreferencesImpl::GetRenderSmoothness() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_RenderSmoothness(&rtVal));
    return rtVal;
}

void PyIAcadDatabasePreferencesImpl::SetSegmentPerPolyline(long val) const
{
    PyThrowBadHr(impObj()->put_SegmentPerPolyline(val));
}

long PyIAcadDatabasePreferencesImpl::GetSegmentPerPolyline() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_SegmentPerPolyline(&rtVal));
    return rtVal;
}

void PyIAcadDatabasePreferencesImpl::SetTextFrameDisplay(bool val) const
{
    PyThrowBadHr(impObj()->put_TextFrameDisplay(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDatabasePreferencesImpl::GetTextFrameDisplay() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextFrameDisplay(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDatabasePreferencesImpl::SetLineweight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_Lineweight((AcLineWeight)val));
}

PyAcLineWeight PyIAcadDatabasePreferencesImpl::GetLineweight() const
{
    AcLineWeight rtVal = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_Lineweight(&rtVal));
    return (PyAcLineWeight)rtVal;
}

void PyIAcadDatabasePreferencesImpl::SetLineWeightDisplay(bool val) const
{
    PyThrowBadHr(impObj()->put_LineWeightDisplay((AcLineWeight)val));
}

bool PyIAcadDatabasePreferencesImpl::GetLineWeightDisplay() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LineWeightDisplay(&rtVal));
    return rtVal != VARIANT_FALSE;
}

IAcadDatabasePreferences* PyIAcadDatabasePreferencesImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDatabasePreferences*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesFilesImpl
PyIAcadPreferencesFilesImpl::PyIAcadPreferencesFilesImpl(IAcadPreferencesFiles* ptr)
    : m_pimpl(ptr)
{
}

void PyIAcadPreferencesFilesImpl::SetSupportPath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_SupportPath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetSupportPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_SupportPath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetDriversPath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_DriversPath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetDriversPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DriversPath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetMenuFile(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_MenuFile(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetMenuFile() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_MenuFile(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetEnterpriseMenuFile(const CString& val)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_EnterpriseMenuFile(bstrVal));
#endif
}

CString PyIAcadPreferencesFilesImpl::GetEnterpriseMenuFile() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_EnterpriseMenuFile(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PyIAcadPreferencesFilesImpl::SetCustomIconPath(const CString& val)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_CustomIconPath(bstrVal));
#endif
}

CString PyIAcadPreferencesFilesImpl::GetCustomIconPath() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_CustomIconPath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PyIAcadPreferencesFilesImpl::SetHelpFilePath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_HelpFilePath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetHelpFilePath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_HelpFilePath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetDefaultInternetURL(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_DefaultInternetURL(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetDefaultInternetURL() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DefaultInternetURL(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyIAcadPreferencesFilesImpl::GetConfigFile() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ConfigFile(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyIAcadPreferencesFilesImpl::GetLicenseServer() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_LicenseServer(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetTextEditor(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_TextEditor(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetTextEditor() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextEditor(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetMainDictionary(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_MainDictionary(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetMainDictionary() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_MainDictionary(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetCustomDictionary(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_CustomDictionary(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetCustomDictionary() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_CustomDictionary(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetAltFontFile(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_AltFontFile(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetAltFontFile() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltFontFile(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetFontFileMap(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_FontFileMap(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetFontFileMap() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_FontFileMap(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetPrintFile(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_PrintFile(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetPrintFile() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_PrintFile(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetPrintSpoolExecutable(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_PrintSpoolExecutable(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetPrintSpoolExecutable() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_PrintSpoolExecutable(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetPostScriptPrologFile(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_PostScriptPrologFile(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetPostScriptPrologFile() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_PostScriptPrologFile(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetPrintSpoolerPath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_PrintSpoolerPath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetPrintSpoolerPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_PrintSpoolerPath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetAutoSavePath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_AutoSavePath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetAutoSavePath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AutoSavePath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetTemplateDwgPath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_TemplateDwgPath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetTemplateDwgPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TemplateDwgPath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetLogFilePath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_LogFilePath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetLogFilePath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_LogFilePath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetTempFilePath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_TempFilePath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetTempFilePath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TempFilePath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetTempXrefPath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_TempXrefPath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetTempXrefPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TempXrefPath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetTextureMapPath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_TextureMapPath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetTextureMapPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextureMapPath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetAltTabletMenuFile(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_AltTabletMenuFile(bstrVal));
}

void PyIAcadPreferencesFilesImpl::SetProjectFilePath(const CString& projectName, const CString& projectFilePath)
{
    _bstr_t bstrprojectName{ projectName };
    _bstr_t bstrprojectFilePath{ projectFilePath };
    PyThrowBadHr(impObj()->SetProjectFilePath(bstrprojectName, bstrprojectFilePath));
}

CString PyIAcadPreferencesFilesImpl::GetProjectFilePath(const CString& projectName) const
{
    _bstr_t bstrVal;
    _bstr_t bstrprojectName{ projectName };
    PyThrowBadHr(impObj()->GetProjectFilePath(bstrprojectName, &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetPrinterConfigPath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_PrinterConfigPath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetPrinterConfigPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_PrinterConfigPath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetPrinterDescPath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_PrinterDescPath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetPrinterDescPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_PrinterDescPath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetPrinterStyleSheetPath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_PrinterStyleSheetPath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetPrinterStyleSheetPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_PrinterStyleSheetPath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetWorkspacePath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_WorkspacePath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetWorkspacePath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_WorkspacePath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetObjectARXPath(const CString& val)
{
    _bstr_t bstrVal{ val };
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->put_ObjectZRXPath(bstrVal));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->put_ObjectARXPath(bstrVal));
#else
    PyThrowBadHr(impObj()->put_ObjectARXPath(bstrVal));
#endif
}

CString PyIAcadPreferencesFilesImpl::GetObjectARXPath() const
{
    _bstr_t bstrVal;

#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->get_ObjectZRXPath(&bstrVal.GetBSTR()));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->get_ObjectARXPath(&bstrVal.GetBSTR()));
#else
    PyThrowBadHr(impObj()->get_ObjectARXPath(&bstrVal.GetBSTR()));
#endif
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetColorBookPath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_ColorBookPath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetColorBookPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ColorBookPath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetToolPalettePath(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_ToolPalettePath(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetToolPalettePath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ToolPalettePath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetQNewTemplateFile(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_QNewTemplateFile(bstrVal));
}

CString PyIAcadPreferencesFilesImpl::GetQNewTemplateFile() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_QNewTemplateFile(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesFilesImpl::SetPlotLogFilePath(const CString& val)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_PlotLogFilePath(bstrVal));
#endif
}

CString PyIAcadPreferencesFilesImpl::GetPlotLogFilePath() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_PlotLogFilePath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PyIAcadPreferencesFilesImpl::SetPageSetupOverridesTemplateFile(const CString& val)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_PageSetupOverridesTemplateFile(bstrVal));
#endif
}

CString PyIAcadPreferencesFilesImpl::GetPageSetupOverridesTemplateFile() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_PageSetupOverridesTemplateFile(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PyIAcadPreferencesFilesImpl::SetActiveInvProject(const CString& val)
{
#if defined(_GRXTARGET250) || defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_ActiveInvProject(bstrVal));
#endif
}

CString PyIAcadPreferencesFilesImpl::GetActiveInvProject() const
{
#if defined(_GRXTARGET250) || defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ActiveInvProject(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

CString PyIAcadPreferencesFilesImpl::GetAltTabletMenuFile() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_AltTabletMenuFile(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

IAcadPreferencesFiles* PyIAcadPreferencesFilesImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesFiles*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesDisplayImpl
PyIAcadPreferencesDisplayImpl::PyIAcadPreferencesDisplayImpl(IAcadPreferencesDisplay* ptr)
    : m_pimpl(ptr)
{
}

void PyIAcadPreferencesDisplayImpl::SetLayoutDisplayMargins(bool val)
{
    PyThrowBadHr(impObj()->put_LayoutDisplayMargins(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesDisplayImpl::GetLayoutDisplayMargins() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LayoutDisplayMargins(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDisplayImpl::SetLayoutDisplayPaper(bool val)
{
    PyThrowBadHr(impObj()->put_LayoutDisplayPaper(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesDisplayImpl::GetLayoutDisplayPaper() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LayoutDisplayPaper(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDisplayImpl::SetLayoutDisplayPaperShadow(bool val)
{
    PyThrowBadHr(impObj()->put_LayoutDisplayPaperShadow(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesDisplayImpl::GetLayoutDisplayPaperShadow() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LayoutDisplayPaperShadow(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDisplayImpl::SetLayoutShowPlotSetup(bool val)
{
    PyThrowBadHr(impObj()->put_LayoutShowPlotSetup(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesDisplayImpl::GetLayoutShowPlotSetup() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LayoutShowPlotSetup(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDisplayImpl::SetLayoutCreateViewport(bool val)
{
    PyThrowBadHr(impObj()->put_LayoutCreateViewport(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesDisplayImpl::GetLayoutCreateViewport() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LayoutCreateViewport(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDisplayImpl::SetDisplayScrollBars(bool val)
{
    PyThrowBadHr(impObj()->put_DisplayScrollBars(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesDisplayImpl::GetDisplayScrollBars() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DisplayScrollBars(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDisplayImpl::SetDisplayScreenMenu(bool val)
{
    PyThrowBadHr(impObj()->put_DisplayScreenMenu(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesDisplayImpl::GetDisplayScreenMenu() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DisplayScreenMenu(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDisplayImpl::SetCursorSize(int val)
{
    PyThrowBadHr(impObj()->put_CursorSize(val));
}

int PyIAcadPreferencesDisplayImpl::GetCursorSize() const
{
    int rtVal;
    PyThrowBadHr(impObj()->get_CursorSize(&rtVal));
    return rtVal;
}

void PyIAcadPreferencesDisplayImpl::SetDockedVisibleLines(int val)
{
    PyThrowBadHr(impObj()->put_DockedVisibleLines(val));
}

int PyIAcadPreferencesDisplayImpl::GetDockedVisibleLines() const
{
    int rtVal;
    PyThrowBadHr(impObj()->get_DockedVisibleLines(&rtVal));
    return rtVal;
}

void PyIAcadPreferencesDisplayImpl::SetShowRasterImage(bool val)
{
    PyThrowBadHr(impObj()->put_ShowRasterImage(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesDisplayImpl::GetShowRasterImage() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ShowRasterImage(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDisplayImpl::SetGraphicsWinModelBackgrndColor(COLORREF val)
{
    PyThrowBadHr(impObj()->put_GraphicsWinModelBackgrndColor((OLE_COLOR)val));
}

COLORREF PyIAcadPreferencesDisplayImpl::GetGraphicsWinModelBackgrndColor() const
{
    COLORREF clrref = 0;
    OLE_COLOR rtVal = 0;
    PyThrowBadHr(impObj()->get_GraphicsWinModelBackgrndColor(&rtVal));
    PyThrowBadHr(OleTranslateColor(rtVal, NULL, &clrref));
    return rtVal;
}

void PyIAcadPreferencesDisplayImpl::SetModelCrosshairColor(COLORREF val)
{
    PyThrowBadHr(impObj()->put_ModelCrosshairColor((OLE_COLOR)val));
}

COLORREF PyIAcadPreferencesDisplayImpl::GetModelCrosshairColor() const
{
    COLORREF clrref = 0;
    OLE_COLOR rtVal = 0;
    PyThrowBadHr(impObj()->get_ModelCrosshairColor(&rtVal));
    PyThrowBadHr(OleTranslateColor(rtVal, NULL, &clrref));
    return rtVal;
}

void PyIAcadPreferencesDisplayImpl::SetGraphicsWinLayoutBackgrndColor(COLORREF val)
{
    PyThrowBadHr(impObj()->put_GraphicsWinLayoutBackgrndColor((OLE_COLOR)val));
}

COLORREF PyIAcadPreferencesDisplayImpl::GetGraphicsWinLayoutBackgrndColor() const
{
    COLORREF clrref = 0;
    OLE_COLOR rtVal = 0;
    PyThrowBadHr(impObj()->get_GraphicsWinLayoutBackgrndColor(&rtVal));
    PyThrowBadHr(OleTranslateColor(rtVal, NULL, &clrref));
    return rtVal;
}

void PyIAcadPreferencesDisplayImpl::SetTextWinBackgrndColor(COLORREF val)
{
    PyThrowBadHr(impObj()->put_TextWinBackgrndColor((OLE_COLOR)val));
}

COLORREF PyIAcadPreferencesDisplayImpl::GetTextWinBackgrndColor() const
{
    COLORREF clrref = 0;
    OLE_COLOR rtVal = 0;
    PyThrowBadHr(impObj()->get_TextWinBackgrndColor(&rtVal));
    PyThrowBadHr(OleTranslateColor(rtVal, NULL, &clrref));
    return rtVal;
}

void PyIAcadPreferencesDisplayImpl::SetTextWinTextColor(COLORREF val)
{
    PyThrowBadHr(impObj()->put_TextWinTextColor((OLE_COLOR)val));
}

COLORREF PyIAcadPreferencesDisplayImpl::GetTextWinTextColor() const
{
    COLORREF clrref = 0;
    OLE_COLOR rtVal = 0;
    PyThrowBadHr(impObj()->get_TextWinTextColor(&rtVal));
    PyThrowBadHr(OleTranslateColor(rtVal, NULL, &clrref));
    return rtVal;
}

void PyIAcadPreferencesDisplayImpl::SetLayoutCrosshairColor(COLORREF val)
{
    PyThrowBadHr(impObj()->put_LayoutCrosshairColor((OLE_COLOR)val));
}

COLORREF PyIAcadPreferencesDisplayImpl::GetLayoutCrosshairColor() const
{
    COLORREF clrref = 0;
    OLE_COLOR rtVal = 0;
    PyThrowBadHr(impObj()->get_LayoutCrosshairColor(&rtVal));
    PyThrowBadHr(OleTranslateColor(rtVal, NULL, &clrref));
    return rtVal;
}

void PyIAcadPreferencesDisplayImpl::SetAutoTrackingVecColor(COLORREF val)
{
    PyThrowBadHr(impObj()->put_AutoTrackingVecColor((OLE_COLOR)val));
}

COLORREF PyIAcadPreferencesDisplayImpl::GetAutoTrackingVecColor() const
{
    COLORREF clrref = 0;
    OLE_COLOR rtVal = 0;
    PyThrowBadHr(impObj()->get_AutoTrackingVecColor(&rtVal));
    PyThrowBadHr(OleTranslateColor(rtVal, NULL, &clrref));
    return rtVal;
}

void PyIAcadPreferencesDisplayImpl::SetTextFont(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_TextFont(bstrVal));
}

CString PyIAcadPreferencesDisplayImpl::GetTextFont() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextFont(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesDisplayImpl::SetTextFontStyle(const PyAcTextFontStyle& val)
{
    PyThrowBadHr(impObj()->put_TextFontStyle((AcTextFontStyle)val));
}

PyAcTextFontStyle PyIAcadPreferencesDisplayImpl::GetTextFontStyle() const
{
    AcTextFontStyle rtVal = (AcTextFontStyle)PyAcTextFontStyle::pyacFontRegular;
    PyThrowBadHr(impObj()->get_TextFontStyle(&rtVal));
    return (PyAcTextFontStyle)rtVal;
}

void PyIAcadPreferencesDisplayImpl::SetTextFontSize(int val)
{
    PyThrowBadHr(impObj()->put_TextFontSize(val));
}

int PyIAcadPreferencesDisplayImpl::GetTextFontSize() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_TextFontSize(&rtVal));
    return rtVal;
}

void PyIAcadPreferencesDisplayImpl::SetHistoryLines(int val)
{
    PyThrowBadHr(impObj()->put_HistoryLines(val));
}

int PyIAcadPreferencesDisplayImpl::GetHistoryLines() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_HistoryLines(&rtVal));
    return rtVal;
}

void PyIAcadPreferencesDisplayImpl::SetMaxAutoCADWindow(bool val)
{
#if defined(_ZRXTARGET)
    impObj()->put_MaxZWCADWindow(val);
#elif defined(_GRXTARGET)
    impObj()->put_MaxAutoCADWindow(val);
#else
    impObj()->put_MaxAutoCADWindow(val);
#endif
}

bool PyIAcadPreferencesDisplayImpl::GetMaxAutoCADWindow() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->get_MaxZWCADWindow(&rtVal));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->get_MaxAutoCADWindow(&rtVal));
#else
    PyThrowBadHr(impObj()->get_MaxAutoCADWindow(&rtVal));
#endif
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDisplayImpl::SetDisplayLayoutTabs(bool val)
{
    PyThrowBadHr(impObj()->put_DisplayLayoutTabs(val));
}

bool PyIAcadPreferencesDisplayImpl::GetDisplayLayoutTabs() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DisplayLayoutTabs(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDisplayImpl::SetImageFrameHighlight(bool val)
{
    PyThrowBadHr(impObj()->put_ImageFrameHighlight(val));
}

bool PyIAcadPreferencesDisplayImpl::GetImageFrameHighlight() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ImageFrameHighlight(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDisplayImpl::SetTrueColorImages(bool val)
{
    PyThrowBadHr(impObj()->put_TrueColorImages(val));
}

bool PyIAcadPreferencesDisplayImpl::GetTrueColorImages() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TrueColorImages(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDisplayImpl::SetXRefFadeIntensity(long val)
{
    PyThrowBadHr(impObj()->put_XRefFadeIntensity(val));
}

long PyIAcadPreferencesDisplayImpl::GetXRefFadeIntensity() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_XRefFadeIntensity(&rtVal));
    return rtVal;
}

IAcadPreferencesDisplay* PyIAcadPreferencesDisplayImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesDisplay*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesOpenSaveImpl
PyIAcadPreferencesOpenSaveImpl::PyIAcadPreferencesOpenSaveImpl(IAcadPreferencesOpenSave* ptr)
    : m_pimpl(ptr)
{
}

void PyIAcadPreferencesOpenSaveImpl::SetSavePreviewThumbnail(bool val)
{
    PyThrowBadHr(impObj()->put_SavePreviewThumbnail(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesOpenSaveImpl::GetSavePreviewThumbnail() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SavePreviewThumbnail(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesOpenSaveImpl::SetIncrementalSavePercent(int val)
{
    PyThrowBadHr(impObj()->put_IncrementalSavePercent(val));
}

int PyIAcadPreferencesOpenSaveImpl::GetIncrementalSavePercent() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_IncrementalSavePercent(&rtVal));
    return rtVal;
}

void PyIAcadPreferencesOpenSaveImpl::SetAutoSaveInterval(int val)
{
    PyThrowBadHr(impObj()->put_AutoSaveInterval(val));
}

int PyIAcadPreferencesOpenSaveImpl::GetAutoSaveInterval() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_AutoSaveInterval(&rtVal));
    return rtVal;
}

void PyIAcadPreferencesOpenSaveImpl::SetCreateBackup(bool val)
{
    PyThrowBadHr(impObj()->put_CreateBackup(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesOpenSaveImpl::GetCreateBackup() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_CreateBackup(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesOpenSaveImpl::SetFullCRCValidation(bool val)
{
    PyThrowBadHr(impObj()->put_FullCRCValidation(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesOpenSaveImpl::GetFullCRCValidation() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_FullCRCValidation(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesOpenSaveImpl::SetLogFileOn(bool val)
{
    PyThrowBadHr(impObj()->put_LogFileOn(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesOpenSaveImpl::GetLogFileOn() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LogFileOn(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesOpenSaveImpl::SetTempFileExtension(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_TempFileExtension(bstrVal));
}

CString PyIAcadPreferencesOpenSaveImpl::GetTempFileExtension() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TempFileExtension(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesOpenSaveImpl::SetXrefDemandLoad(PyAcXRefDemandLoad val)
{
    PyThrowBadHr(impObj()->put_XrefDemandLoad((AcXRefDemandLoad)val));
}

PyAcXRefDemandLoad PyIAcadPreferencesOpenSaveImpl::GetXrefDemandLoad() const
{
    AcXRefDemandLoad val = (AcXRefDemandLoad)PyAcXRefDemandLoad::pyacDemandLoadDisabled;
    PyThrowBadHr(impObj()->get_XrefDemandLoad(&val));
    return (PyAcXRefDemandLoad)val;
}

void PyIAcadPreferencesOpenSaveImpl::SetDemandLoadARXApp(PyAcARXDemandLoad val)
{
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->put_DemandLoadZRXApp((AcARXDemandLoad)val));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->put_DemandLoadARXApp((AcARXDemandLoad)val));
#else
    PyThrowBadHr(impObj()->put_DemandLoadARXApp((AcARXDemandLoad)val));
#endif
}

PyAcARXDemandLoad PyIAcadPreferencesOpenSaveImpl::GetDemandLoadARXApp() const
{
    AcARXDemandLoad val = (AcARXDemandLoad)PyAcARXDemandLoad::pyacDemanLoadDisable;
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->get_DemandLoadZRXApp(&val));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->get_DemandLoadARXApp(&val));
#else
    PyThrowBadHr(impObj()->get_DemandLoadARXApp(&val));
#endif
    return (PyAcARXDemandLoad)val;
}

void PyIAcadPreferencesOpenSaveImpl::SetProxyImage(PyAcProxyImage val)
{
    PyThrowBadHr(impObj()->put_ProxyImage((AcProxyImage)val));
}

PyAcProxyImage PyIAcadPreferencesOpenSaveImpl::GetProxyImage() const
{
    AcProxyImage val = (AcProxyImage)PyAcProxyImage::pyacProxyNotShow;
    PyThrowBadHr(impObj()->get_ProxyImage(&val));
    return (PyAcProxyImage)val;
}

void PyIAcadPreferencesOpenSaveImpl::SetShowProxyDialogBox(bool val)
{
    PyThrowBadHr(impObj()->put_ShowProxyDialogBox(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesOpenSaveImpl::GetShowProxyDialogBox() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ShowProxyDialogBox(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesOpenSaveImpl::SetAutoAudit(bool val)
{
    PyThrowBadHr(impObj()->put_AutoAudit(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesOpenSaveImpl::GetAutoAudit() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AutoAudit(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesOpenSaveImpl::SetSaveAsType(PyAcSaveAsType val)
{
    PyThrowBadHr(impObj()->put_SaveAsType((AcSaveAsType)val));
}

PyAcSaveAsType PyIAcadPreferencesOpenSaveImpl::GetSaveAsType() const
{
    AcSaveAsType val = (AcSaveAsType)PyAcSaveAsType::pyac2018_dwg;
    PyThrowBadHr(impObj()->get_SaveAsType(&val));
    return (PyAcSaveAsType)val;
}

long PyIAcadPreferencesOpenSaveImpl::GetMRUNumber()
{
    long val = 0;
    PyThrowBadHr(impObj()->get_MRUNumber(&val));
    return val;
}

IAcadPreferencesOpenSave* PyIAcadPreferencesOpenSaveImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesOpenSave*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesOutputImpl
PyIAcadPreferencesOutputImpl::PyIAcadPreferencesOutputImpl(IAcadPreferencesOutput* ptr)
    : m_pimpl(ptr)
{
}

void PyIAcadPreferencesOutputImpl::SetDefaultOutputDevice(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_DefaultOutputDevice(bstrVal));
}

CString PyIAcadPreferencesOutputImpl::GetDefaultOutputDevice() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DefaultOutputDevice(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesOutputImpl::SetPrinterSpoolAlert(PyAcPrinterSpoolAlert val)
{
    PyThrowBadHr(impObj()->put_PrinterSpoolAlert(AcPrinterSpoolAlert(val)));
}

PyAcPrinterSpoolAlert PyIAcadPreferencesOutputImpl::GetPrinterSpoolAlert() const
{
    AcPrinterSpoolAlert val = (AcPrinterSpoolAlert)PyAcPrinterSpoolAlert::pyacPrinterAlwaysAlert;
    PyThrowBadHr(impObj()->get_PrinterSpoolAlert(&val));
    return (PyAcPrinterSpoolAlert)val;
}

void PyIAcadPreferencesOutputImpl::SetPrinterPaperSizeAlert(bool val)
{
    PyThrowBadHr(impObj()->put_PrinterPaperSizeAlert(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesOutputImpl::GetPrinterPaperSizeAlert() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_PrinterPaperSizeAlert(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesOutputImpl::SetPlotLegacy(bool val)
{
    PyThrowBadHr(impObj()->put_PlotLegacy(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesOutputImpl::GetPlotLegacy() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_PlotLegacy(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesOutputImpl::SetOLEQuality(PyAcOleQuality val)
{
    PyThrowBadHr(impObj()->put_OLEQuality((AcOleQuality)val));
}

PyAcOleQuality PyIAcadPreferencesOutputImpl::GetOLEQuality() const
{
    AcOleQuality val = (AcOleQuality)PyAcOleQuality::pyacOQLineArt;
    PyThrowBadHr(impObj()->get_OLEQuality(&val));
    return (PyAcOleQuality)val;
}

void PyIAcadPreferencesOutputImpl::SetUseLastPlotSettings(bool val)
{
    PyThrowBadHr(impObj()->put_UseLastPlotSettings(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesOutputImpl::GetUseLastPlotSettings() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_UseLastPlotSettings(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesOutputImpl::SetPlotPolicy(PyAcPlotPolicy val)
{
    PyThrowBadHr(impObj()->put_PlotPolicy((AcPlotPolicy)val));
}

PyAcPlotPolicy PyIAcadPreferencesOutputImpl::GetPlotPolicy() const
{
    AcPlotPolicy val = (AcPlotPolicy)PyAcPlotPolicy::pyacPolicyNamed;
    PyThrowBadHr(impObj()->get_PlotPolicy(&val));
    return (PyAcPlotPolicy)val;
}

void PyIAcadPreferencesOutputImpl::SetDefaultPlotStyleTable(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_DefaultPlotStyleTable(bstrVal));
}

CString PyIAcadPreferencesOutputImpl::GetDefaultPlotStyleTable() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DefaultPlotStyleTable(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesOutputImpl::SetDefaultPlotStyleForObjects(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_DefaultPlotStyleForObjects(bstrVal));
}

CString PyIAcadPreferencesOutputImpl::GetDefaultPlotStyleForObjects() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DefaultPlotStyleForObjects(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesOutputImpl::SetDefaultPlotStyleForLayer(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_DefaultPlotStyleForLayer(bstrVal));
}

CString PyIAcadPreferencesOutputImpl::GetDefaultPlotStyleForLayer() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DefaultPlotStyleForLayer(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesOutputImpl::SetContinuousPlotLog(bool val)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadHr(impObj()->put_ContinuousPlotLog(val ? VARIANT_TRUE : VARIANT_FALSE));
#endif
}

bool PyIAcadPreferencesOutputImpl::GetContinuousPlotLog() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ContinuousPlotLog(&rtVal));
    return rtVal != VARIANT_FALSE;
#endif
}

void PyIAcadPreferencesOutputImpl::SetAutomaticPlotLog(bool val)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadHr(impObj()->put_AutomaticPlotLog(val ? VARIANT_TRUE : VARIANT_FALSE));
#endif
}

bool PyIAcadPreferencesOutputImpl::GetAutomaticPlotLog() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AutomaticPlotLog(&rtVal));
    return rtVal != VARIANT_FALSE;
#endif
}

void PyIAcadPreferencesOutputImpl::SetDefaultPlotToFilePath(const CString& val)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_DefaultPlotToFilePath(bstrVal));
#endif
}

CString PyIAcadPreferencesOutputImpl::GetDefaultPlotToFilePath() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_DefaultPlotToFilePath(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

IAcadPreferencesOutput* PyIAcadPreferencesOutputImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesOutput*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesSystemImpl
PyIAcadPreferencesSystemImpl::PyIAcadPreferencesSystemImpl(IAcadPreferencesSystem* ptr)
    : m_pimpl(ptr)
{
}

void PyIAcadPreferencesSystemImpl::SetSingleDocumentMode(bool val)
{
    PyThrowBadHr(impObj()->put_SingleDocumentMode(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesSystemImpl::GetSingleDocumentMode() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SingleDocumentMode(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesSystemImpl::SetDisplayOLEScale(bool val)
{
    PyThrowBadHr(impObj()->put_DisplayOLEScale(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesSystemImpl::GetDisplayOLEScale() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DisplayOLEScale(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesSystemImpl::SetStoreSQLIndex(bool val)
{
    PyThrowBadHr(impObj()->put_StoreSQLIndex(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesSystemImpl::GetStoreSQLIndex() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_StoreSQLIndex(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesSystemImpl::SetTablesReadOnly(bool val)
{
    PyThrowBadHr(impObj()->put_TablesReadOnly(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesSystemImpl::GetTablesReadOnly() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TablesReadOnly(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesSystemImpl::SetEnableStartupDialog(bool val)
{
    PyThrowBadHr(impObj()->put_EnableStartupDialog(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesSystemImpl::GetEnableStartupDialog() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_EnableStartupDialog(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesSystemImpl::SetBeepOnError(bool val)
{
    PyThrowBadHr(impObj()->put_BeepOnError(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesSystemImpl::GetBeepOnError() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_BeepOnError(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesSystemImpl::SetShowWarningMessages(bool val)
{
    PyThrowBadHr(impObj()->put_ShowWarningMessages(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesSystemImpl::GetShowWarningMessages() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ShowWarningMessages(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesSystemImpl::SetLoadAcadLspInAllDocuments(bool val)
{
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->put_LoadZcadLspInAllDocuments(val ? VARIANT_TRUE : VARIANT_FALSE));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->put_LoadGcadLspInAllDocuments(val ? VARIANT_TRUE : VARIANT_FALSE));
#else
    PyThrowBadHr(impObj()->put_LoadAcadLspInAllDocuments(val ? VARIANT_TRUE : VARIANT_FALSE));
#endif
}

bool PyIAcadPreferencesSystemImpl::GetLoadAcadLspInAllDocuments() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;

#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->get_LoadZcadLspInAllDocuments(&rtVal));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->get_LoadGcadLspInAllDocuments(&rtVal));
#else
    PyThrowBadHr(impObj()->get_LoadAcadLspInAllDocuments(&rtVal));
#endif
    return rtVal != VARIANT_FALSE;
}

IAcadPreferencesSystem* PyIAcadPreferencesSystemImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesSystem*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesUserImpl
PyIAcadPreferencesUserImpl::PyIAcadPreferencesUserImpl(IAcadPreferencesUser* ptr)
    : m_pimpl(ptr)
{
}

void PyIAcadPreferencesUserImpl::SetKeyboardAccelerator(PyAcKeyboardAccelerator val)
{
    PyThrowBadHr(impObj()->put_KeyboardAccelerator((AcKeyboardAccelerator)val));
}

PyAcKeyboardAccelerator PyIAcadPreferencesUserImpl::GetKeyboardAccelerator() const
{
    AcKeyboardAccelerator val = (AcKeyboardAccelerator)PyAcKeyboardAccelerator::pyacPreferenceClassic;
    PyThrowBadHr(impObj()->get_KeyboardAccelerator(&val));
    return (PyAcKeyboardAccelerator)val;
}

void PyIAcadPreferencesUserImpl::SetKeyboardPriority(PyAcKeyboardPriority val)
{
    PyThrowBadHr(impObj()->put_KeyboardPriority((AcKeyboardPriority)val));
}

PyAcKeyboardPriority PyIAcadPreferencesUserImpl::GetKeyboardPriority() const
{
    AcKeyboardPriority val = (AcKeyboardPriority)PyAcKeyboardPriority::pyacKeyboardRunningObjSnap;
    PyThrowBadHr(impObj()->get_KeyboardPriority(&val));
    return (PyAcKeyboardPriority)val;
}

void PyIAcadPreferencesUserImpl::SetHyperlinkDisplayCursor(bool val)
{
    PyThrowBadHr(impObj()->put_HyperlinkDisplayCursor(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesUserImpl::GetHyperlinkDisplayCursor() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_HyperlinkDisplayCursor(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesUserImpl::SetADCInsertUnitsDefaultSource(PyAcInsertUnits val)
{
    PyThrowBadHr(impObj()->put_ADCInsertUnitsDefaultSource((AcInsertUnits)val));
}

PyAcInsertUnits PyIAcadPreferencesUserImpl::GetADCInsertUnitsDefaultSource() const
{
    AcInsertUnits val = (AcInsertUnits)PyAcInsertUnits::pyacInsertUnitsUnitless;
    PyThrowBadHr(impObj()->get_ADCInsertUnitsDefaultSource(&val));
    return (PyAcInsertUnits)val;
}

void PyIAcadPreferencesUserImpl::SetADCInsertUnitsDefaultTarget(PyAcInsertUnits val)
{
    PyThrowBadHr(impObj()->put_ADCInsertUnitsDefaultTarget((AcInsertUnits)val));
}

PyAcInsertUnits PyIAcadPreferencesUserImpl::GetADCInsertUnitsDefaultTarget() const
{
    AcInsertUnits val = (AcInsertUnits)PyAcInsertUnits::pyacInsertUnitsUnitless;
    PyThrowBadHr(impObj()->get_ADCInsertUnitsDefaultTarget(&val));
    return (PyAcInsertUnits)val;
}

void PyIAcadPreferencesUserImpl::SetShortCutMenuDisplay(bool val)
{
    PyThrowBadHr(impObj()->put_ShortCutMenuDisplay(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesUserImpl::GetShortCutMenuDisplay() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ShortCutMenuDisplay(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesUserImpl::SetSCMDefaultMode(PyAcDrawingAreaSCMDefault val)
{
    PyThrowBadHr(impObj()->put_SCMDefaultMode((AcDrawingAreaSCMDefault)val));
}

PyAcDrawingAreaSCMDefault PyIAcadPreferencesUserImpl::GetSCMDefaultMode() const
{
    AcDrawingAreaSCMDefault val = (AcDrawingAreaSCMDefault)PyAcDrawingAreaSCMDefault::pyacRepeatLastCommand;
    PyThrowBadHr(impObj()->get_SCMDefaultMode(&val));
    return (PyAcDrawingAreaSCMDefault)val;
}

void PyIAcadPreferencesUserImpl::SetSCMEditMode(PyAcDrawingAreaSCMEdit val)
{
    PyThrowBadHr(impObj()->put_SCMEditMode((AcDrawingAreaSCMEdit)val));
}

PyAcDrawingAreaSCMEdit PyIAcadPreferencesUserImpl::GetSCMEditMode() const
{
    AcDrawingAreaSCMEdit val = (AcDrawingAreaSCMEdit)PyAcDrawingAreaSCMEdit::pyacEdRepeatLastCommand;
    PyThrowBadHr(impObj()->get_SCMEditMode(&val));
    return (PyAcDrawingAreaSCMEdit)val;
}

void PyIAcadPreferencesUserImpl::SetSCMCommandMode(PyAcDrawingAreaSCMCommand val)
{
    PyThrowBadHr(impObj()->put_SCMCommandMode((AcDrawingAreaSCMCommand)val));
}

PyAcDrawingAreaSCMCommand PyIAcadPreferencesUserImpl::GetSCMCommandMode() const
{
    AcDrawingAreaSCMCommand val = (AcDrawingAreaSCMCommand)PyAcDrawingAreaSCMCommand::pyacEnter;
    PyThrowBadHr(impObj()->get_SCMCommandMode(&val));
    return (PyAcDrawingAreaSCMCommand)val;
}

void PyIAcadPreferencesUserImpl::SetSCMTimeMode(bool val)
{
    PyThrowBadHr(impObj()->put_SCMTimeMode(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesUserImpl::GetSCMTimeMode() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SCMTimeMode(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesUserImpl::SetSCMTimeValue(int val)
{
    PyThrowBadHr(impObj()->put_SCMTimeValue(val));
}

int PyIAcadPreferencesUserImpl::GetSCMTimeValue() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_SCMTimeValue(&val));
    return val;
}

IAcadPreferencesUser* PyIAcadPreferencesUserImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesUser*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesDraftingImpl
PyIAcadPreferencesDraftingImpl::PyIAcadPreferencesDraftingImpl(IAcadPreferencesDrafting* ptr)
    : m_pimpl(ptr)
{
}

void PyIAcadPreferencesDraftingImpl::SetAutoSnapMarker(bool val)
{
    PyThrowBadHr(impObj()->put_AutoSnapMarker(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesDraftingImpl::GetAutoSnapMarker() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AutoSnapMarker(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDraftingImpl::SetAutoSnapMagnet(bool val)
{
    PyThrowBadHr(impObj()->put_AutoSnapMagnet(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesDraftingImpl::GetAutoSnapMagnet() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AutoSnapMagnet(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDraftingImpl::SetAutoSnapTooltip(bool val)
{
    PyThrowBadHr(impObj()->put_AutoSnapTooltip(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesDraftingImpl::GetAutoSnapTooltip() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AutoSnapTooltip(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDraftingImpl::SetAutoSnapAperture(bool val)
{
    PyThrowBadHr(impObj()->put_AutoSnapAperture(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesDraftingImpl::GetAutoSnapAperture() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AutoSnapAperture(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDraftingImpl::SetAutoSnapApertureSize(long val)
{
    PyThrowBadHr(impObj()->put_AutoSnapApertureSize(val));
}

long PyIAcadPreferencesDraftingImpl::GetAutoSnapApertureSize() const
{
    long rtVal;
    PyThrowBadHr(impObj()->get_AutoSnapApertureSize(&rtVal));
    return rtVal;
}

void PyIAcadPreferencesDraftingImpl::SetAutoSnapMarkerColor(PyAcColor val)
{
    PyThrowBadHr(impObj()->put_AutoSnapMarkerColor((AcColor)val));
}

PyAcColor PyIAcadPreferencesDraftingImpl::GetAutoSnapMarkerColor() const
{
    AcColor clr = (AcColor)PyAcColor::pyacBlue;
    PyThrowBadHr(impObj()->get_AutoSnapMarkerColor(&clr));
    return (PyAcColor)clr;
}

void PyIAcadPreferencesDraftingImpl::SetAutoSnapMarkerSize(long val)
{
    PyThrowBadHr(impObj()->put_AutoSnapMarkerSize(val));
}

long PyIAcadPreferencesDraftingImpl::GetAutoSnapMarkerSize() const
{
    long rtVal;
    PyThrowBadHr(impObj()->get_AutoSnapMarkerSize(&rtVal));
    return rtVal;
}

void PyIAcadPreferencesDraftingImpl::SetPolarTrackingVector(bool val)
{
    PyThrowBadHr(impObj()->put_PolarTrackingVector(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesDraftingImpl::GetPolarTrackingVector() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_PolarTrackingVector(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDraftingImpl::SetFullScreenTrackingVector(bool val)
{
    PyThrowBadHr(impObj()->put_FullScreenTrackingVector(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesDraftingImpl::GetFullScreenTrackingVector() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_FullScreenTrackingVector(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDraftingImpl::SetAutoTrackTooltip(bool val)
{
    PyThrowBadHr(impObj()->put_AutoTrackTooltip(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesDraftingImpl::GetAutoTrackTooltip() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AutoTrackTooltip(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesDraftingImpl::SetAlignmentPointAcquisition(PyAcAlignmentPointAcquisition val)
{
    PyThrowBadHr(impObj()->put_AlignmentPointAcquisition((AcAlignmentPointAcquisition)val));
}

PyAcAlignmentPointAcquisition PyIAcadPreferencesDraftingImpl::GetAlignmentPointAcquisition() const
{
    AcAlignmentPointAcquisition val = (AcAlignmentPointAcquisition)PyAcAlignmentPointAcquisition::pyacAlignPntAcquisitionAutomatic;
    PyThrowBadHr(impObj()->get_AlignmentPointAcquisition(&val));
    return (PyAcAlignmentPointAcquisition)val;
}

IAcadPreferencesDrafting* PyIAcadPreferencesDraftingImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesDrafting*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesSelectionImpl
PyIAcadPreferencesSelectionImpl::PyIAcadPreferencesSelectionImpl(IAcadPreferencesSelection* ptr)
    : m_pimpl(ptr)
{
}

void PyIAcadPreferencesSelectionImpl::SetPickFirst(bool val)
{
    PyThrowBadHr(impObj()->put_PickFirst(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesSelectionImpl::GetPickFirst() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_PickFirst(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesSelectionImpl::SetPickAdd(bool val)
{
    PyThrowBadHr(impObj()->put_PickAdd(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesSelectionImpl::GetPickAdd() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_PickAdd(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesSelectionImpl::SetPickDrag(bool val)
{
    PyThrowBadHr(impObj()->put_PickDrag(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesSelectionImpl::GetPickDrag() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_PickDrag(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesSelectionImpl::SetPickAuto(bool val)
{
    PyThrowBadHr(impObj()->put_PickAuto(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesSelectionImpl::GetPickAuto() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_PickAuto(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesSelectionImpl::SetPickBoxSize(long val)
{
    PyThrowBadHr(impObj()->put_PickBoxSize(val));
}

long PyIAcadPreferencesSelectionImpl::GetPickBoxSize() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_PickBoxSize(&rtVal));
    return rtVal;
}

void PyIAcadPreferencesSelectionImpl::SetDisplayGrips(bool val)
{
#if defined(_BRXTARGET250)
    PyThrowBadHr(impObj()->put_DisplayGrips(val ? 1 : 0));
#else
    PyThrowBadHr(impObj()->put_DisplayGrips(val ? VARIANT_TRUE : VARIANT_FALSE));
#endif
}

bool PyIAcadPreferencesSelectionImpl::GetDisplayGrips() const
{
#if defined(_BRXTARGET250)
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_DisplayGrips(&rtVal));
    return rtVal != 0;
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DisplayGrips(&rtVal));
    return rtVal != VARIANT_FALSE;
#endif
}

void PyIAcadPreferencesSelectionImpl::SetDisplayGripsWithinBlocks(bool val)
{
    PyThrowBadHr(impObj()->put_DisplayGripsWithinBlocks(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesSelectionImpl::GetDisplayGripsWithinBlocks() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DisplayGripsWithinBlocks(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPreferencesSelectionImpl::SetGripColorSelected(PyAcColor val)
{
    PyThrowBadHr(impObj()->put_GripColorSelected((AcColor)val));
}

PyAcColor PyIAcadPreferencesSelectionImpl::GetGripColorSelected() const
{
    AcColor clr = (AcColor)PyAcColor::pyacRed;
    PyThrowBadHr(impObj()->get_GripColorSelected(&clr));
    return (PyAcColor)clr;

}

void PyIAcadPreferencesSelectionImpl::SetGripColorUnselected(PyAcColor val)
{
    PyThrowBadHr(impObj()->put_GripColorUnselected((AcColor)val));
}

PyAcColor PyIAcadPreferencesSelectionImpl::GetGripColorUnselected() const
{
    AcColor clr = (AcColor)PyAcColor::pyacBlue;
    PyThrowBadHr(impObj()->get_GripColorUnselected(&clr));
    return (PyAcColor)clr;
}

void PyIAcadPreferencesSelectionImpl::SetGripSize(long val)
{
#if defined(_ARXTARGET250)
    resbuf rb;
    rb.restype = RTSHORT;
    rb.resval.rint = val;
    PyThrowBadRt(acedSetVar(L"GRIPSIZE", &rb));
#else
    PyThrowBadHr(impObj()->put_GripSize(val));
#endif
}

long PyIAcadPreferencesSelectionImpl::GetGripSize() const
{
#if defined(_ARXTARGET250)
    resbuf rb;
    PyThrowBadRt(acedGetVar(L"GRIPSIZE", &rb));
    return rb.resval.rint;
#else
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_GripSize(&rtVal));
    return rtVal;
#endif
}

void PyIAcadPreferencesSelectionImpl::SetPickGroup(bool val)
{
    PyThrowBadHr(impObj()->put_PickGroup(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPreferencesSelectionImpl::GetPickGroup() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_PickGroup(&rtVal));
    return rtVal != VARIANT_FALSE;
}

IAcadPreferencesSelection* PyIAcadPreferencesSelectionImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesSelection*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesProfilesImpl
PyIAcadPreferencesProfilesImpl::PyIAcadPreferencesProfilesImpl(IAcadPreferencesProfiles* ptr)
    : m_pimpl(ptr)
{
}

CString PyIAcadPreferencesProfilesImpl::GetActiveProfile() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ActiveProfile(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPreferencesProfilesImpl::SetActiveProfile(const CString& str)
{
    _bstr_t bstrVal{ str };
    PyThrowBadHr(impObj()->put_ActiveProfile(bstrVal));
}

void PyIAcadPreferencesProfilesImpl::ImportProfile(const CString& ProfileName, const CString& RegFile, bool IncludePathInfo)
{
    _bstr_t bstrProfileName{ ProfileName };
    _bstr_t bstrRegFile{ RegFile };
    VARIANT_BOOL vtIncludePathInfo = IncludePathInfo ? VARIANT_TRUE : VARIANT_FALSE;
    PyThrowBadHr(impObj()->ImportProfile(bstrProfileName, bstrRegFile, vtIncludePathInfo));
}

void PyIAcadPreferencesProfilesImpl::ExportProfile(const CString& ProfileName, const CString& RegFile)
{
    _bstr_t bstrProfileName{ ProfileName };
    _bstr_t bstrRegFile{ RegFile };
    PyThrowBadHr(impObj()->ExportProfile(bstrProfileName, bstrRegFile));
}

void PyIAcadPreferencesProfilesImpl::DeleteProfile(const CString& ProfileName)
{
    _bstr_t bstrProfileName{ ProfileName };
    PyThrowBadHr(impObj()->DeleteProfile(bstrProfileName));
}

void PyIAcadPreferencesProfilesImpl::ResetProfile(const CString& Profile)
{
    _bstr_t bstrProfile{ Profile };
    PyThrowBadHr(impObj()->ResetProfile(bstrProfile));
}

void PyIAcadPreferencesProfilesImpl::RenameProfile(const CString& origProfileName, const CString& newProfileName)
{
    _bstr_t bstrorigProfileName{ origProfileName };
    _bstr_t bstrnewProfileName{ newProfileName };
    PyThrowBadHr(impObj()->RenameProfile(bstrorigProfileName, bstrnewProfileName));
}

void PyIAcadPreferencesProfilesImpl::CopyProfile(const CString& oldProfileName, const CString& newProfileName)
{
    _bstr_t bstroldProfileName{ oldProfileName };
    _bstr_t bstrnewProfileName{ newProfileName };
    PyThrowBadHr(impObj()->CopyProfile(bstroldProfileName, bstrnewProfileName));
}

wstringArray PyIAcadPreferencesProfilesImpl::GetAllProfileNames() const
{
    VARIANT rtVal;
    wstringArray vec;
    VariantInit(&rtVal);
    PyThrowBadHr(impObj()->GetAllProfileNames(&rtVal));
    {
        ULONG pcElem = 0;
        PWSTR* prgsz = nullptr;
        if (VariantToStringArrayAlloc(rtVal, &prgsz, &pcElem) == S_OK)
        {
            vec = wstringArray(prgsz, prgsz + pcElem);
            CoTaskMemFree(prgsz);
        }
    }
    return vec;
}

IAcadPreferencesProfiles* PyIAcadPreferencesProfilesImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesProfiles*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesImpl
PyIAcadPreferencesImpl::PyIAcadPreferencesImpl(IAcadPreferences* ptr)
    : m_pimpl(ptr)
{
}

PyIAcadPreferencesFilesPtr PyIAcadPreferencesImpl::GetFiles() const
{
    IAcadPreferencesFiles* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Files(&ptr));
    return std::make_unique<PyIAcadPreferencesFilesImpl>(ptr);
}

PyIAcadPreferencesDisplayPtr PyIAcadPreferencesImpl::GetDisplay() const
{
    IAcadPreferencesDisplay* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Display(&ptr));
    return std::make_unique<PyIAcadPreferencesDisplayImpl>(ptr);
}

PyIAcadPreferencesOpenSavePtr PyIAcadPreferencesImpl::GetOpenSave() const
{
    IAcadPreferencesOpenSave* ptr = nullptr;
    PyThrowBadHr(impObj()->get_OpenSave(&ptr));
    return std::make_unique<PyIAcadPreferencesOpenSaveImpl>(ptr);
}

PyIAcadPreferencesOutputPtr PyIAcadPreferencesImpl::GetOutput() const
{
    IAcadPreferencesOutput* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Output(&ptr));
    return std::make_unique<PyIAcadPreferencesOutputImpl>(ptr);
}

PyIAcadPreferencesSystemPtr PyIAcadPreferencesImpl::GetSystem() const
{
    IAcadPreferencesSystem* ptr = nullptr;
    PyThrowBadHr(impObj()->get_System(&ptr));
    return std::make_unique<PyIAcadPreferencesSystemImpl>(ptr);
}

PyIAcadPreferencesUserPtr PyIAcadPreferencesImpl::GetUser() const
{
    IAcadPreferencesUser* ptr = nullptr;
    PyThrowBadHr(impObj()->get_User(&ptr));
    return std::make_unique<PyIAcadPreferencesUserImpl>(ptr);
}

PyIAcadPreferencesDraftingPtr PyIAcadPreferencesImpl::GetDrafting() const
{
    IAcadPreferencesDrafting* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Drafting(&ptr));
    return std::make_unique<PyIAcadPreferencesDraftingImpl>(ptr);
}

PyIAcadPreferencesSelectionPtr PyIAcadPreferencesImpl::GetSelection() const
{
    IAcadPreferencesSelection* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Selection(&ptr));
    return std::make_unique<PyIAcadPreferencesSelectionImpl>(ptr);
}

PyIAcadPreferencesProfilesPtr PyIAcadPreferencesImpl::GetProfiles() const
{
    IAcadPreferencesProfiles* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Profiles(&ptr));
    return std::make_unique<PyIAcadPreferencesProfilesImpl>(ptr);
}

IAcadPreferences* PyIAcadPreferencesImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferences*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSummaryInfoImpl
PyIAcadSummaryInfoImpl::PyIAcadSummaryInfoImpl(IAcadSummaryInfo* ptr)
    : m_pimpl(ptr)
{
}

IAcadSummaryInfo* PyIAcadSummaryInfoImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSummaryInfo*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDynamicBlockReferencePropertyImpl
PyIAcadDynamicBlockReferencePropertyImpl::PyIAcadDynamicBlockReferencePropertyImpl(IAcadDynamicBlockReferenceProperty* ptr)
    : m_pimpl(ptr)
{
}

IAcadDynamicBlockReferenceProperty* PyIAcadDynamicBlockReferencePropertyImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDynamicBlockReferenceProperty*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadIdPairImpl
PyIAcadIdPairImpl::PyIAcadIdPairImpl(IAcadIdPair* ptr)
    : m_pimpl(ptr)
{
}

IAcadIdPair* PyIAcadIdPairImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadIdPair*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadShadowDisplayImpl
#ifndef _BRXTARGET
PyIAcadShadowDisplayImpl::PyIAcadShadowDisplayImpl(IAcadShadowDisplay* ptr)
    : m_pimpl(ptr)
{
}

PyAcShadowDisplayType PyIAcadShadowDisplayImpl::GetShadowDisplay() const
{
    AcShadowDisplayType rtVal = static_cast<AcShadowDisplayType>(PyAcShadowDisplayType::pyacCastsShadows);
    PyThrowBadHr(impObj()->get_ShadowDisplay(&rtVal));
    return static_cast<PyAcShadowDisplayType>(rtVal);
}

void PyIAcadShadowDisplayImpl::PutShadowDisplay(PyAcShadowDisplayType val)
{
    PyThrowBadHr(impObj()->put_ShadowDisplay(static_cast<AcShadowDisplayType>(val)));
}

bool PyIAcadShadowDisplayImpl::GetEnableShadowDisplay()
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_EnableShadowDisplay(&rtVal));
    return rtVal != 0;
}

IAcadShadowDisplay* PyIAcadShadowDisplayImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadShadowDisplay*>(m_pimpl.GetInterfacePtr());
}
#endif

//------------------------------------------------------------------------------------
//PyIAcadPlotImpl
PyIAcadPlotImpl::PyIAcadPlotImpl(IAcadPlot* ptr)
    : m_pimpl(ptr)
{
}

bool PyIAcadPlotImpl::GetQuietErrorMode() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_QuietErrorMode(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPlotImpl::SetQuietErrorMode(bool val)
{
    PyThrowBadHr(impObj()->put_QuietErrorMode(val ? VARIANT_TRUE : VARIANT_FALSE));
}

long PyIAcadPlotImpl::GetNumberOfCopies() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_NumberOfCopies(&rtVal));
    return rtVal;
}

void PyIAcadPlotImpl::SetNumberOfCopies(long val)
{
    PyThrowBadHr(impObj()->put_NumberOfCopies(val));
}

bool PyIAcadPlotImpl::GetBatchPlotProgress() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_BatchPlotProgress(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPlotImpl::SetBatchPlotProgress(bool val)
{
    PyThrowBadHr(impObj()->put_BatchPlotProgress(val ? VARIANT_TRUE : VARIANT_FALSE));
}

void PyIAcadPlotImpl::SetDisplayPlotPreview(PyAcPreviewMode mode)
{
    PyThrowBadHr(impObj()->DisplayPlotPreview(static_cast<AcPreviewMode>(mode)));
}

void PyIAcadPlotImpl::SetLayoutsToPlot(const wstringArray& layouts)
{
    _variant_t rtVal;
    InitVariantFromStringArray((PCWSTR*)layouts.data(), layouts.size(), &rtVal.GetVARIANT());
    PyThrowBadHr(impObj()->SetLayoutsToPlot(rtVal));
}

void PyIAcadPlotImpl::StartBatchMode(long val)
{
    PyThrowBadHr(impObj()->StartBatchMode(val));
}

IAcadPlot* PyIAcadPlotImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPlot*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadMenuBarImpl
PyIAcadMenuBarImpl::PyIAcadMenuBarImpl(IAcadMenuBar* ptr)
    : m_pimpl(ptr)
{
}

long PyIAcadMenuBarImpl::GetCount() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Count(&val));
    return val;
}

PyIAcadPopupMenuPtr PyIAcadMenuBarImpl::GetItem(long index) const
{
    _variant_t val{ index };
    IAcadPopupMenu* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return std::make_unique<PyIAcadPopupMenuImpl>(ptr);
}

IAcadMenuBar* PyIAcadMenuBarImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMenuBar*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadMenuGroupImpl
PyIAcadMenuGroupImpl::PyIAcadMenuGroupImpl(IAcadMenuGroup* ptr)
    : m_pimpl(ptr)
{
}

PyIAcadMenuGroupsPtr PyIAcadMenuGroupImpl::GetParent() const
{
    IAcadMenuGroups* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Parent(&ptr));
    return std::make_unique<PyIAcadMenuGroupsImpl>(ptr);
}

CString PyIAcadMenuGroupImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

PyAcMenuGroupType PyIAcadMenuGroupImpl::GetType() const
{
    AcMenuGroupType mtype = static_cast<AcMenuGroupType>(PyAcMenuGroupType::pyacBaseMenuGroup);
    PyThrowBadHr(impObj()->get_Type(&mtype));
    return static_cast<PyAcMenuGroupType>(mtype);
}

CString PyIAcadMenuGroupImpl::GetMenuFileName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_MenuFileName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

PyIAcadPopupMenusPtr PyIAcadMenuGroupImpl::GetMenus() const
{
    IAcadPopupMenus* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Menus(&ptr));
    return std::make_unique<PyIAcadPopupMenusImpl>(ptr);
}

PyIAcadToolbarsPtr PyIAcadMenuGroupImpl::GetToolbars() const
{
    IAcadToolbars* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Toolbars(&ptr));
    return std::make_unique<PyIAcadToolbarsImpl>(ptr);
}

void PyIAcadMenuGroupImpl::Save(PyAcMenuFileType menuType)
{
    PyThrowBadHr(impObj()->Save(AcMenuFileType(menuType)));
}

void PyIAcadMenuGroupImpl::SaveAs(const CString& menuFileName, PyAcMenuFileType menuType)
{
    _bstr_t bstrmenuFileName{ menuFileName };
    PyThrowBadHr(impObj()->SaveAs(bstrmenuFileName, AcMenuFileType(menuType)));
}

void PyIAcadMenuGroupImpl::Unload()
{
    PyThrowBadHr(impObj()->Unload());
}

IAcadMenuGroup* PyIAcadMenuGroupImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMenuGroup*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadMenuGroupsImpl
PyIAcadMenuGroupsImpl::PyIAcadMenuGroupsImpl(IAcadMenuGroups* ptr)
    : m_pimpl(ptr)
{
}

long PyIAcadMenuGroupsImpl::GetCount() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Count(&val));
    return val;
}

PyIAcadMenuGroupPtr PyIAcadMenuGroupsImpl::GetItem(long index) const
{
    _variant_t val{ index };
    IAcadMenuGroup* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return std::make_unique<PyIAcadMenuGroupImpl>(ptr);
}

PyIAcadMenuGroupPtr PyIAcadMenuGroupsImpl::Load(const CString& menuFileName)
{
    IAcadMenuGroup* ptr = nullptr;
    _bstr_t bstrmenuFileName{ menuFileName };
    PyThrowBadHr(impObj()->Load(bstrmenuFileName, vtMissing, &ptr));
    return std::make_unique<PyIAcadMenuGroupImpl>(ptr);
}

PyIAcadMenuGroupPtr PyIAcadMenuGroupsImpl::Load(const CString& menuFileName, const PyIAcadMenuGroupImpl& BaseMenu)
{
    IAcadMenuGroup* ptr = nullptr;
    _bstr_t bstrmenuFileName{ menuFileName };
    _variant_t vtBaseMenu{ static_cast<IDispatch*>(BaseMenu.impObj()) };
    PyThrowBadHr(impObj()->Load(bstrmenuFileName, vtBaseMenu, &ptr));
    return std::make_unique<PyIAcadMenuGroupImpl>(ptr);
}

IAcadMenuGroups* PyIAcadMenuGroupsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMenuGroups*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPopupMenuItemImpl
PyIAcadPopupMenuItemImpl::PyIAcadPopupMenuItemImpl(IAcadPopupMenuItem* ptr)
    : m_pimpl(ptr)
{
}

PyIAcadPopupMenuPtr PyIAcadPopupMenuItemImpl::GetParent() const
{
    IAcadPopupMenu* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Parent(&ptr));
    return std::make_unique<PyIAcadPopupMenuImpl>(ptr);
}

CString PyIAcadPopupMenuItemImpl::GetLabel() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Label(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPopupMenuItemImpl::SetLabel(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_Label(bstrVal));
}

CString PyIAcadPopupMenuItemImpl::GetTagString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TagString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPopupMenuItemImpl::SetTagString(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_TagString(bstrVal));
}

bool PyIAcadPopupMenuItemImpl::GetEnable() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Enable(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPopupMenuItemImpl::SetEnable(bool val)
{
    PyThrowBadHr(impObj()->put_Enable(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPopupMenuItemImpl::GetCheck() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Check(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPopupMenuItemImpl::SetCheck(bool val)
{
    PyThrowBadHr(impObj()->put_Enable(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcMenuItemType PyIAcadPopupMenuItemImpl::GetType() const
{
    AcMenuItemType val = (AcMenuItemType)PyAcMenuItemType::pyacMenuItem;
    PyThrowBadHr(impObj()->get_Type(&val));
    return (PyAcMenuItemType)val;
}

PyIAcadPopupMenuPtr PyIAcadPopupMenuItemImpl::GetSubMenu() const
{
    IAcadPopupMenu* ptr = nullptr;
    PyThrowBadHr(impObj()->get_SubMenu(&ptr));
    return std::make_unique<PyIAcadPopupMenuImpl>(ptr);
}

CString PyIAcadPopupMenuItemImpl::GetMacro() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Macro(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPopupMenuItemImpl::SetMacro(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_Macro(bstrVal));
}

int PyIAcadPopupMenuItemImpl::GetIndex() const
{
    int idx = 0;
    PyThrowBadHr(impObj()->get_Index(&idx));
    return idx;
}

CString PyIAcadPopupMenuItemImpl::GetCaption() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Caption(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyIAcadPopupMenuItemImpl::GetHelpString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_HelpString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPopupMenuItemImpl::SetHelpString(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_HelpString(bstrVal));
}

void PyIAcadPopupMenuItemImpl::Delete()
{
    PyThrowBadHr(impObj()->Delete());
}

int PyIAcadPopupMenuItemImpl::GetEndSubMenuLevel() const
{
    int idx = 0;
    PyThrowBadHr(impObj()->get_EndSubMenuLevel(&idx));
    return idx;
}

void PyIAcadPopupMenuItemImpl::SetEndSubMenuLevel(int idx) const
{
    PyThrowBadHr(impObj()->put_EndSubMenuLevel(idx));
}

IAcadPopupMenuItem* PyIAcadPopupMenuItemImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPopupMenuItem*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPopupMenuImpl
PyIAcadPopupMenuImpl::PyIAcadPopupMenuImpl(IAcadPopupMenu* ptr)
    : m_pimpl(ptr)
{
}

long PyIAcadPopupMenuImpl::GetCount() const
{
    long index = 0;
    PyThrowBadHr(impObj()->get_Count(&index));
    return index;
}

PyIAcadPopupMenuItemPtr PyIAcadPopupMenuImpl::GetItem(long index) const
{
    _variant_t val{ index };
    IAcadPopupMenuItem* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return std::make_unique<PyIAcadPopupMenuItemImpl>(ptr);
}

PyIAcadPopupMenusPtr PyIAcadPopupMenuImpl::GetParent() const
{
    IDispatch* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Parent(&ptr));
    return std::make_unique<PyIAcadPopupMenusImpl>((IAcadPopupMenus*)ptr);
}

CString PyIAcadPopupMenuImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPopupMenuImpl::SetName(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_Name(bstrVal));
}

CString PyIAcadPopupMenuImpl::GetNameNoMnemonic() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_NameNoMnemonic(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

bool PyIAcadPopupMenuImpl::GetShortcutMenu() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ShortcutMenu(&rtVal));
    return rtVal != VARIANT_FALSE;
}

bool PyIAcadPopupMenuImpl::GetOnMenuBar() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_OnMenuBar(&rtVal));
    return rtVal != VARIANT_FALSE;
}

PyIAcadPopupMenuItemPtr PyIAcadPopupMenuImpl::AddMenuItem(long index, const CString& label, const CString& macro)
{
    _variant_t vtindex{ index };
    _bstr_t bstrlabel{ label };
    _bstr_t bstrmacro{ macro };
    IAcadPopupMenuItem* ptr;
    PyThrowBadHr(impObj()->AddMenuItem(vtindex, bstrlabel, bstrmacro, &ptr));
    return std::make_unique<PyIAcadPopupMenuItemImpl>(ptr);

}

PyIAcadPopupMenuPtr PyIAcadPopupMenuImpl::AddSubMenu(long index, const CString& label)
{
    _variant_t vtindex{ index };
    _bstr_t bstrlabel{ label };
    IAcadPopupMenu* ptr;
    PyThrowBadHr(impObj()->AddSubMenu(vtindex, bstrlabel, &ptr));
    return std::make_unique<PyIAcadPopupMenuImpl>(ptr);
}

PyIAcadPopupMenuItemPtr PyIAcadPopupMenuImpl::AddSeparator(long index) const
{
    _variant_t vtindex{ index };
    IAcadPopupMenuItem* ptr;
    PyThrowBadHr(impObj()->AddSeparator(vtindex, &ptr));
    return std::make_unique<PyIAcadPopupMenuItemImpl>(ptr);
}

void PyIAcadPopupMenuImpl::InsertInMenuBar(long index) const
{
    _variant_t vtindex{ index };
    PyThrowBadHr(impObj()->InsertInMenuBar(vtindex));
}

void PyIAcadPopupMenuImpl::RemoveFromMenuBar() const
{
    PyThrowBadHr(impObj()->RemoveFromMenuBar());
}

CString PyIAcadPopupMenuImpl::GetTagString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TagString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

IAcadPopupMenu* PyIAcadPopupMenuImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPopupMenu*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPopupMenusImpl
PyIAcadPopupMenusImpl::PyIAcadPopupMenusImpl(IAcadPopupMenus* ptr)
    : m_pimpl(ptr)
{
}

long PyIAcadPopupMenusImpl::GetCount() const
{
    long index = 0;
    PyThrowBadHr(impObj()->get_Count(&index));
    return index;
}

PyIAcadPopupMenuPtr PyIAcadPopupMenusImpl::GetItem(long index) const
{
    _variant_t val{ index };
    IAcadPopupMenu* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return std::make_unique<PyIAcadPopupMenuImpl>(ptr);
}

PyIAcadMenuGroupPtr PyIAcadPopupMenusImpl::GetParent() const
{
    IAcadMenuGroup* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Parent(&ptr));
    return std::make_unique<PyIAcadMenuGroupImpl>(ptr);
}

PyIAcadPopupMenuPtr PyIAcadPopupMenusImpl::Add(const CString& toolbarName)
{
    _bstr_t bstrVal{ toolbarName };
    IAcadPopupMenu* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrVal, &ptr));
    return std::make_unique<PyIAcadPopupMenuImpl>(ptr);
}

void PyIAcadPopupMenusImpl::InsertMenuInMenuBar(const CString& menuName, long index)
{
    _bstr_t bstrVal{ menuName };
    _variant_t vtindex{ index };
    PyThrowBadHr(impObj()->InsertMenuInMenuBar(bstrVal, vtindex));
}

void PyIAcadPopupMenusImpl::RemoveMenuFromMenuBar(long index)
{
    _variant_t vtindex{ index };
    PyThrowBadHr(impObj()->RemoveMenuFromMenuBar(vtindex));
}

IAcadPopupMenus* PyIAcadPopupMenusImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPopupMenus*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadToolbarItemImpl
PyIAcadToolbarItemImpl::PyIAcadToolbarItemImpl(IAcadToolbarItem* ptr)
    : m_pimpl(ptr)
{
}

PyIAcadToolbarPtr PyIAcadToolbarItemImpl::GetParent() const
{
    IAcadToolbar* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Parent(&ptr));
    return std::make_unique<PyIAcadToolbarImpl>(ptr);
}

CString PyIAcadToolbarItemImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadToolbarItemImpl::SetName(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_Name(bstrVal));
}

CString PyIAcadToolbarItemImpl::GetTagString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TagString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadToolbarItemImpl::SetTagString(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_TagString(bstrVal));
}

PyAcToolbarItemType PyIAcadToolbarItemImpl::GetType() const
{
    AcToolbarItemType val = static_cast<AcToolbarItemType>(PyAcToolbarItemType::pyacToolbarButton);
    PyThrowBadHr(impObj()->get_Type(&val));
    return static_cast<PyAcToolbarItemType>(val);
}

CString PyIAcadToolbarItemImpl::GetMacro() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Macro(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadToolbarItemImpl::SetMacro(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_Macro(bstrVal));
}

int PyIAcadToolbarItemImpl::GetIndex() const
{
    int index = 0;
    PyThrowBadHr(impObj()->get_Index(&index));
    return index;
}

CString PyIAcadToolbarItemImpl::GetHelpString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_HelpString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadToolbarItemImpl::SetHelpString(const CString& val) const
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_HelpString(bstrVal));
}

std::pair<CString, CString> PyIAcadToolbarItemImpl::GetBitmaps() const
{
    _bstr_t bstrSmallIconName;
    _bstr_t bstrLargeIconName;
    PyThrowBadHr(impObj()->GetBitmaps(&bstrSmallIconName.GetBSTR(), &bstrLargeIconName.GetBSTR()));
    return { CString{(LPCTSTR)bstrSmallIconName}, CString{(LPCTSTR)bstrLargeIconName} };
}

void PyIAcadToolbarItemImpl::SetBitmaps(const CString& smallIconName, const CString& largeIconName)
{
    _bstr_t bstrsmallIconName{ smallIconName };
    _bstr_t bstrslargeIconName{ largeIconName };
    PyThrowBadHr(impObj()->SetBitmaps(bstrsmallIconName, bstrslargeIconName));
}

void PyIAcadToolbarItemImpl::AttachToolbarToFlyout(const CString& menuGroupName, const CString& toolbarName)
{
    _bstr_t bstrmenuGroupName{ menuGroupName };
    _bstr_t bstrtoolbarName{ toolbarName };
    PyThrowBadHr(impObj()->AttachToolbarToFlyout(bstrmenuGroupName, bstrtoolbarName));
}

void PyIAcadToolbarItemImpl::Delete()
{
    PyThrowBadHr(impObj()->Delete());
}

CString PyIAcadToolbarItemImpl::GetCommandDisplayName() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_CommandDisplayName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PyIAcadToolbarItemImpl::SetCommandDisplayName(const CString& val)
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_CommandDisplayName(bstrVal));
#endif
}

IAcadToolbarItem* PyIAcadToolbarItemImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadToolbarItem*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadToolbarImpl
PyIAcadToolbarImpl::PyIAcadToolbarImpl(IAcadToolbar* ptr)
    : m_pimpl(ptr)
{
}

long PyIAcadToolbarImpl::GetCount() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Count(&val));
    return val;
}

PyIAcadToolbarItemPtr PyIAcadToolbarImpl::GetItem(long index) const
{
    _variant_t val{ index };
    IAcadToolbarItem* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return std::make_unique<PyIAcadToolbarItemImpl>(ptr);
}

PyIAcadToolbarsPtr PyIAcadToolbarImpl::GetParent() const
{
    IDispatch* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Parent(&ptr));
    return std::make_unique<PyIAcadToolbarsImpl>(static_cast<IAcadToolbars*>(ptr));
}

CString PyIAcadToolbarImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadToolbarImpl::SetName(const CString& name)
{
    _bstr_t bstrVal{ name };
    PyThrowBadHr(impObj()->put_Name(bstrVal));
}

bool PyIAcadToolbarImpl::GetVisible() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Visible(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadToolbarImpl::SetVisible(bool val)
{
    PyThrowBadHr(impObj()->put_Visible(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcToolbarDockStatus PyIAcadToolbarImpl::GetDockStatus() const
{
    AcToolbarDockStatus rtVal = AcToolbarDockStatus(PyAcToolbarDockStatus::pyacToolbarDockBottom);
    PyThrowBadHr(impObj()->get_DockStatus(&rtVal));
    return static_cast<PyAcToolbarDockStatus>(rtVal);
}

bool PyIAcadToolbarImpl::GetLargeButtons() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LargeButtons(&rtVal));
    return rtVal != VARIANT_FALSE;
}

int PyIAcadToolbarImpl::GetLeft() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_left(&rtVal));
    return rtVal;
}

void PyIAcadToolbarImpl::SetLeft(int val)
{
    PyThrowBadHr(impObj()->put_left(val));
}

int PyIAcadToolbarImpl::GetTop() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_top(&rtVal));
    return rtVal;
}

void PyIAcadToolbarImpl::SetTop(int val)
{
    PyThrowBadHr(impObj()->put_top(val));
}

int PyIAcadToolbarImpl::GetWidth() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_Width(&rtVal));
    return rtVal;
}

int PyIAcadToolbarImpl::GetHeight() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_Height(&rtVal));
    return rtVal;
}

int PyIAcadToolbarImpl::GetFloatingRows() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_FloatingRows(&rtVal));
    return rtVal;
}

void PyIAcadToolbarImpl::SetFloatingRows(int val)
{
    PyThrowBadHr(impObj()->put_FloatingRows(val));
}

CString PyIAcadToolbarImpl::GetHelpString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_HelpString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadToolbarImpl::SetHelpString(const CString& val) const
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_HelpString(bstrVal));
}

PyIAcadToolbarItemPtr PyIAcadToolbarImpl::AddToolbarButton(int index, const CString& name, const CString& helpstr, const CString& macro, bool flyoutButton)
{
    _variant_t vtindex{ index };
    _bstr_t bstrname{ name };
    _bstr_t bstrhelpstr{ helpstr };
    _bstr_t bstrmacro{ macro };
    _variant_t vtflyoutButton{ flyoutButton };
    IAcadToolbarItem* ptr = nullptr;
    PyThrowBadHr(impObj()->AddToolbarButton(vtindex, bstrname, bstrhelpstr, bstrmacro, vtflyoutButton, &ptr));
    return std::make_unique<PyIAcadToolbarItemImpl>(ptr);
}

void PyIAcadToolbarImpl::Dock(PyAcToolbarDockStatus val)
{
    PyThrowBadHr(impObj()->Dock((AcToolbarDockStatus)val));
}

void PyIAcadToolbarImpl::Float(int top, int teft, int numberFloatRows)
{
    PyThrowBadHr(impObj()->Float(top, teft, numberFloatRows));
}

void PyIAcadToolbarImpl::Delete()
{
    PyThrowBadHr(impObj()->Delete());
}

CString PyIAcadToolbarImpl::GetTagString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TagString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

IAcadToolbar* PyIAcadToolbarImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadToolbar*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadToolbarsImpl
PyIAcadToolbarsImpl::PyIAcadToolbarsImpl(IAcadToolbars* ptr)
    : m_pimpl(ptr)
{
}

long PyIAcadToolbarsImpl::GetCount() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Count(&val));
    return val;
}

PyIAcadToolbarPtr PyIAcadToolbarsImpl::GetItem(long index) const
{
    _variant_t val{ index };
    IAcadToolbar* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return std::make_unique<PyIAcadToolbarImpl>(ptr);
}

PyIAcadMenuGroupPtr PyIAcadToolbarsImpl::GetParent() const
{
    IAcadMenuGroup* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Parent(&ptr));
    return std::make_unique<PyIAcadMenuGroupImpl>(ptr);
}

bool PyIAcadToolbarsImpl::GetLargeButtons() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LargeButtons(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadToolbarsImpl::SetLargeButtons(bool val) const
{
    PyThrowBadHr(impObj()->put_LargeButtons(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyIAcadToolbarPtr PyIAcadToolbarsImpl::Add(const CString& toolbarName)
{
    _bstr_t bstrtoolbarName{ toolbarName };
    IAcadToolbar* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrtoolbarName, &ptr));
    return std::make_unique<PyIAcadToolbarImpl>(ptr);
}

IAcadToolbars* PyIAcadToolbarsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadToolbars*>(m_pimpl.GetInterfacePtr());
}
