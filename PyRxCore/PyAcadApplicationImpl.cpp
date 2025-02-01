#include "stdafx.h"
#include "PyAcadApplicationImpl.h"

//------------------------------------------------------------------------------------
//PyAcadStateImpl
PyIAcadStateImpl::PyIAcadStateImpl(IAcadState* ptr)
    : m_pimpl(ptr)
{
}

bool PyIAcadStateImpl::getIsQuiescent() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_IsQuiescent(&rtVal));
    return rtVal != VARIANT_FALSE;
}

IAcadState* PyIAcadStateImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadState*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDatabaseImpl
PyIAcadDatabaseImpl::PyIAcadDatabaseImpl(IAcadDatabase* ptr)
    : m_pimpl(ptr)
{
}

PyIAcadSummaryInfoPtr PyIAcadDatabaseImpl::GetSummaryInfo() const
{
    IAcadSummaryInfo* ptr = nullptr;
    PyThrowBadHr(impObj()->get_SummaryInfo(&ptr));
    return std::make_unique<PyIAcadSummaryInfoImpl>(ptr);
}

IAcadDatabase* PyIAcadDatabaseImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDatabase*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDocumentImpl
PyIAcadDocumentImpl::PyIAcadDocumentImpl(IAcadDocument* ptr)
    : PyIAcadDatabaseImpl(ptr)
{
}

PyIAcadPlotPtr PyIAcadDocumentImpl::GetPlot() const
{
    IAcadPlot* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Plot(&ptr));
    return std::make_unique<PyIAcadPlotImpl>(ptr);
}

PyIAcadLayerPtr PyIAcadDocumentImpl::GetActiveLayer() const
{
    IAcadLayer* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveLayer(&ptr));
    return std::make_unique<PyIAcadLayerImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveLayer(const PyIAcadLayerImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveLayer(obj.impObj()));
}

PyIAcadLineTypePtr PyIAcadDocumentImpl::GetActiveLinetype() const
{
    IAcadLineType* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveLinetype(&ptr));
    return std::make_unique<PyIAcadLineTypeImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveLinetype(const PyIAcadLineTypeImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveLinetype(obj.impObj()));
}

PyIAcadDimStylePtr PyIAcadDocumentImpl::GetActiveDimStyle() const
{
    IAcadDimStyle* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveDimStyle(&ptr));
    return std::make_unique<PyIAcadDimStyleImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveDimStyle(const PyIAcadDimStyleImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveDimStyle(obj.impObj()));
}

PyIAcadTextStylePtr PyIAcadDocumentImpl::GetActiveTextStyle() const
{
    IAcadTextStyle* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveTextStyle(&ptr));
    return std::make_unique<PyIAcadTextStyleImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveTextStyle(const PyIAcadTextStyleImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveTextStyle(obj.impObj()));
}

PyIAcadUCSPtr PyIAcadDocumentImpl::GetActiveUCS() const
{
    IAcadUCS* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveUCS(&ptr));
    return std::make_unique<PyIAcadUCSImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveUCS(const PyIAcadUCSImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveUCS(obj.impObj()));
}

PyIAcadViewportPtr PyIAcadDocumentImpl::GetActiveViewport() const
{
    IAcadViewport* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveViewport(&ptr));
    return std::make_unique<PyIAcadViewportImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveViewport(const PyIAcadViewportImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveViewport(obj.impObj()));
}

PyIAcadPViewportPtr PyIAcadDocumentImpl::GetActivePViewport() const
{
    IAcadPViewport* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActivePViewport(&ptr));
    return std::make_unique<PyIAcadPViewportImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActivePViewport(const PyIAcadPViewportImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActivePViewport(obj.impObj()));
}

PyAcActiveSpace PyIAcadDocumentImpl::GetActiveSpace() const
{
    AcActiveSpace sp = (AcActiveSpace)PyAcActiveSpace::pyacModelSpace;
    PyThrowBadHr(impObj()->get_ActiveSpace(&sp));
    return static_cast<PyAcActiveSpace>(sp);
}

void PyIAcadDocumentImpl::SetActiveSpace(PyAcActiveSpace sp) const
{
    PyThrowBadHr(impObj()->put_ActiveSpace(static_cast<AcActiveSpace>(sp)));
}

PyIAcadSelectionSetsPtr PyIAcadDocumentImpl::GetSelectionSets() const
{
    IAcadSelectionSets* ptr = nullptr;
    PyThrowBadHr(impObj()->get_SelectionSets(&ptr));
    return std::make_unique<PyIAcadSelectionSetsImpl>(ptr);
}

PyIAcadSelectionSetPtr PyIAcadDocumentImpl::GetActiveSelectionSet() const
{
    IAcadSelectionSet* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveSelectionSet(&ptr));
    return std::make_unique<PyIAcadSelectionSetImpl>(ptr);
}

CString PyIAcadDocumentImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyIAcadDocumentImpl::GetFullName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_FullName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyIAcadDocumentImpl::GetPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Path(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

bool PyIAcadDocumentImpl::GetObjectSnapMode() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ObjectSnapMode(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDocumentImpl::SetObjectSnapMode(bool flag)
{
    PyThrowBadHr(impObj()->put_ObjectSnapMode(flag ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDocumentImpl::GetReadOnly() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ReadOnly(&rtVal));
    return rtVal != VARIANT_FALSE;
}

bool PyIAcadDocumentImpl::GetSaved() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Saved(&rtVal));
    return rtVal != VARIANT_FALSE;
}

bool PyIAcadDocumentImpl::GetMSpace() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_MSpace(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDocumentImpl::SetMSpace(bool flag)
{
    PyThrowBadHr(impObj()->put_MSpace(flag ? VARIANT_TRUE : VARIANT_FALSE));
}

PyIAcadUtilityPtr PyIAcadDocumentImpl::GetUtility() const
{
    IAcadUtility* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Utility(&ptr));
    return std::make_unique<PyIAcadUtilityImpl>(ptr);
}

PyIAcadDocumentPtr PyIAcadDocumentImpl::Open(const CString& path)
{
    VARIANT passwd;
    VariantInit(&passwd);// no longer supported
    _bstr_t bstrpath{ path };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Open(bstrpath, passwd, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

void PyIAcadDocumentImpl::AuditInfo(bool flag)
{
    PyThrowBadHr(impObj()->AuditInfo(flag ? VARIANT_TRUE : VARIANT_FALSE));
}

PyIAcadBlockReferencePtr PyIAcadDocumentImpl::Import(const CString& path, const AcGePoint3d& InsertionPoint, double ScaleFactor)
{
    _bstr_t bstrpath{ path };
    VARIANT vaInsertionPoint;
    VariantInit(&vaInsertionPoint);
    constexpr ULONG s = sizeof(AcGePoint3d) / sizeof(double);
    PyThrowBadHr(InitVariantFromDoubleArray(asDblArray(InsertionPoint), s, &vaInsertionPoint));
    IDispatch* ptr = nullptr;
    PyThrowBadHr(impObj()->Import(bstrpath, vaInsertionPoint, ScaleFactor, &ptr));
    return std::make_unique<PyIAcadBlockReferenceImpl>((IAcadBlockReference*)ptr); //test
}

void PyIAcadDocumentImpl::Export(const CString& fileName, const CString& extension, const PyIAcadSelectionSetImpl& sset)
{
    _bstr_t bstrfileName{ fileName };
    _bstr_t bstrextension{ extension };
    PyThrowBadHr(impObj()->Export(bstrfileName, bstrextension, sset.impObj()));
}

PyIAcadDocumentPtr PyIAcadDocumentImpl::New(const CString& path)
{
    _bstr_t bstrpath{ path };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->New(bstrpath, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

void PyIAcadDocumentImpl::Save()
{
    PyThrowBadHr(impObj()->Save());
}

void PyIAcadDocumentImpl::SaveAs(const CString& fileName)
{
    _bstr_t bstrpath{ fileName };
    PyThrowBadHr(impObj()->SaveAs(bstrpath));
}

void PyIAcadDocumentImpl::SaveAs(const CString& fileName, PyAcSaveAsType saType)
{
    _bstr_t bstrpath{ fileName };
    _variant_t vasaType{ saType };
    PyThrowBadHr(impObj()->SaveAs(bstrpath, vasaType));
}

void PyIAcadDocumentImpl::SaveAs(const CString& fileName, PyAcSaveAsType saType, const PyIAcadSecurityParamsImpl& pr)
{
    _bstr_t bstrpath{ fileName };
    _variant_t vasaType{ saType };
    _variant_t vapr{ (IDispatch*)pr.impObj() };
    PyThrowBadHr(impObj()->SaveAs(bstrpath, vasaType, vapr));
}

void PyIAcadDocumentImpl::Wblock(const CString& fileName, const PyIAcadSelectionSetImpl& sset)
{
    _bstr_t bstrpath{ fileName };
    PyThrowBadHr(impObj()->Wblock(bstrpath, sset.impObj()));
}

void PyIAcadDocumentImpl::PurgeAll()
{
    PyThrowBadHr(impObj()->PurgeAll());
}

TypedVariant PyIAcadDocumentImpl::GetVariable(const CString& name)
{
    _bstr_t bstrname{ name };
    _variant_t variantItem;
    PyThrowBadHr(impObj()->GetVariable(bstrname, &variantItem.GetVARIANT()));

    if (IsVariantString(variantItem))
    {
        std::wstring val(wcslen(variantItem.bstrVal) + 1, '\0');
        if (CHECKHR(VariantToString(variantItem, val.data(), val.size())))
            return TypedVariant{ RTSTR, val };
    }
    else if (variantItem.vt == VT_I2 || variantItem.vt == VT_UI2)
    {
        int16_t val = 0;
        if (CHECKHR(VariantToInt16(variantItem, &val)))
            return TypedVariant{ RTSHORT, val };
    }
    else if (variantItem.vt == VT_I4 || variantItem.vt == VT_UI4)
    {
        int32_t val = 0;
        if (CHECKHR(VariantToInt32(variantItem, &val)))
            return TypedVariant{ RTLONG, val };
    }
    else if (variantItem.vt == VT_R4 || variantItem.vt == VT_R8)
    {
        double val = .0;
        if (CHECKHR(VariantToDouble(variantItem, &val)))
            return TypedVariant{ RTREAL, val };
    }
    else if (IsVariantArray(variantItem))
    {
        AcGePoint3d val;
        ULONG pcElem = 0;
        constexpr ULONG szof = sizeof(AcGePoint3d) / sizeof(double);
        if (CHECKHR(VariantToDoubleArray(variantItem, asDblArray(val), szof, &pcElem)))
            return TypedVariant{ RT3DPOINT, val };
    }
    acutPrintf(_T("\nUnrecognised variant %ls, %ld"), __FUNCTIONW__, __LINE__);
    return TypedVariant{ RTNONE, 0 };
}

void PyIAcadDocumentImpl::SetVariable(const CString& name, const TypedVariant& tv)
{
    _variant_t variantOut;
    _bstr_t bstrname{ name };
    switch (tv.code)
    {
        case RTSHORT:
        {
            if (CHECKHR(InitVariantFromInt16(std::get<TypedVariant::kInt16>(tv.variant), &variantOut.GetVARIANT())))
                PyThrowBadHr(impObj()->SetVariable(bstrname, variantOut));
            return;
        }
        case RTLONG:
        {
            if (CHECKHR(InitVariantFromInt32(std::get<TypedVariant::kInt32>(tv.variant), &variantOut.GetVARIANT())))
                PyThrowBadHr(impObj()->SetVariable(bstrname, variantOut));
            return;
        }
        case RTREAL:
        {
            if (CHECKHR(InitVariantFromDouble(std::get<TypedVariant::kFloat>(tv.variant), &variantOut.GetVARIANT())))
                PyThrowBadHr(impObj()->SetVariable(bstrname, variantOut));
            return;
        }
        case RTSTR:
        {
            if (CHECKHR(InitVariantFromString(std::get<TypedVariant::kString>(tv.variant).c_str(), &variantOut.GetVARIANT())))
                PyThrowBadHr(impObj()->SetVariable(bstrname, variantOut));
            return;
        }
        case RT3DPOINT:
        {
            constexpr ULONG len = sizeof(AcGePoint3d) / sizeof(double);
            if (CHECKHR(InitVariantFromDoubleArray(asDblArray(std::get<TypedVariant::kPoint3d>(tv.variant)), len, &variantOut.GetVARIANT())))
                PyThrowBadHr(impObj()->SetVariable(bstrname, variantOut));
            return;
        }
        default:
        {
            acutPrintf(_T("\nUnrecognised variant %ls, %ld"), __FUNCTIONW__, __LINE__);
            break;
        }
    }
}

void PyIAcadDocumentImpl::LoadShapeFile(const CString& name)
{
    _bstr_t bstrpath{ name };
    PyThrowBadHr(impObj()->LoadShapeFile(bstrpath));
}

void PyIAcadDocumentImpl::Regen(PyAcRegenType rt)
{
    PyThrowBadHr(impObj()->Regen(AcRegenType(rt)));
}

PyIAcadSelectionSetPtr PyIAcadDocumentImpl::GetPickfirstSelectionSet() const
{
#if defined(_BRXTARGET250)
    IDispatch* ptr = nullptr;
    PyThrowBadHr(impObj()->get_PickfirstSelectionSet(&ptr));
    return std::make_unique<PyIAcadSelectionSetImpl>((IAcadSelectionSet*)ptr);
#else
    IAcadSelectionSet* ptr = nullptr;
    PyThrowBadHr(impObj()->get_PickfirstSelectionSet(&ptr));
    return std::make_unique<PyIAcadSelectionSetImpl>(ptr);
#endif
}

bool PyIAcadDocumentImpl::IsActive()
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Active(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDocumentImpl::Activate()
{
    PyThrowBadHr(impObj()->Activate());
}

void PyIAcadDocumentImpl::Close()
{
    PyThrowBadHr(impObj()->Close());
}

void PyIAcadDocumentImpl::Close(bool SaveChanges)
{
    _variant_t vtSaveChanges{ SaveChanges };
    PyThrowBadHr(impObj()->Close(vtSaveChanges));
}

void PyIAcadDocumentImpl::Close(bool SaveChanges, const CString& fileName)
{
    _variant_t vtSaveChanges{ SaveChanges };
    _variant_t vtFilename{ fileName };
    PyThrowBadHr(impObj()->Close(vtSaveChanges, vtFilename));
}

PyAcWindowState PyIAcadDocumentImpl::GetWindowState() const
{
    AcWindowState val = (AcWindowState)PyAcWindowState::pyacNorm;
    PyThrowBadHr(impObj()->get_WindowState(&val));
    return (PyAcWindowState)val;
}

void PyIAcadDocumentImpl::SetWindowState(PyAcWindowState val)
{
    PyThrowBadHr(impObj()->put_WindowState(AcWindowState(val)));
}

int PyIAcadDocumentImpl::GetWidth() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_Width(&val));
    return val;
}

void PyIAcadDocumentImpl::SetWidth(int val)
{
    PyThrowBadHr(impObj()->put_Width(val));
}

int PyIAcadDocumentImpl::GetHeight() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_Height(&val));
    return val;
}

void PyIAcadDocumentImpl::SetHeight(int val)
{
    PyThrowBadHr(impObj()->put_Height(val));
}

PyIAcadLayoutPtr PyIAcadDocumentImpl::GetActiveLayout() const
{
    IAcadLayout* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveLayout(&ptr));
    return std::make_unique<PyIAcadLayoutImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveLayout(const PyIAcadLayoutImpl& val)
{
    PyThrowBadHr(impObj()->put_ActiveLayout(val.impObj()));
}

void PyIAcadDocumentImpl::SendCommand(const CString& cmd)
{
    _bstr_t bstrcmd{ cmd };
    PyThrowBadHr(impObj()->SendCommand(bstrcmd));
}

void PyIAcadDocumentImpl::PostCommand(const CString& cmd)
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET240)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrcmd{ cmd };
    PyThrowBadHr(impObj()->PostCommand(bstrcmd));
#endif
}

LONG_PTR PyIAcadDocumentImpl::GetHWND() const
{
    LONG_PTR val = 0;
    PyThrowBadHr(impObj()->get_HWND(&val));
    return val;
}

CString PyIAcadDocumentImpl::GetWindowTitle() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_WindowTitle(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDocumentImpl::StartUndoMark()
{
    PyThrowBadHr(impObj()->StartUndoMark());
}

void PyIAcadDocumentImpl::EndUndoMark()
{
    PyThrowBadHr(impObj()->EndUndoMark());
}

PyIAcadDatabasePtr PyIAcadDocumentImpl::GetDatabase() const
{
#if defined(_BRXTARGET250)
    IAcadDatabase* ptr = nullptr;
    PyThrowBadHr(impObj()->get_database(&ptr));
    return std::make_unique<PyIAcadDatabaseImpl>(ptr);
#else
    IAcadDatabase* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Database(&ptr));
    return std::make_unique<PyIAcadDatabaseImpl>(ptr);
#endif
}

PyIAcadMaterialPtr PyIAcadDocumentImpl::GetActiveMaterial() const
{
    IAcadMaterial* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveMaterial(&ptr));
    return std::make_unique<PyIAcadMaterialImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveMaterial(const PyIAcadMaterialImpl& val)
{
    PyThrowBadHr(impObj()->put_ActiveMaterial(val.impObj()));
}

IAcadDocument* PyIAcadDocumentImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDocument*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDocumentsImpl
PyIAcadDocumentsImpl::PyIAcadDocumentsImpl(IAcadDocuments* ptr)
    : m_pimpl(ptr)
{
}

long PyIAcadDocumentsImpl::GetCount() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Count(&val));
    return val;
}

PyIAcadDocumentPtr PyIAcadDocumentsImpl::Add()
{
    VARIANT rtVal;
    VariantInit(&rtVal);
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(rtVal, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

PyIAcadDocumentPtr PyIAcadDocumentsImpl::Add(const CString& _template)
{
    _variant_t val{ static_cast<const wchar_t*>(_template) };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(val, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

void PyIAcadDocumentsImpl::Close()
{
    PyThrowBadHr(impObj()->Close());
}

PyIAcadDocumentPtr PyIAcadDocumentsImpl::GetItem(long index) const
{
    _variant_t val{ index };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

PyIAcadDocumentPtr PyIAcadDocumentsImpl::Open(const CString& path, bool readOnly)
{
    VARIANT passwd;
    VariantInit(&passwd);// no longer supported
    _bstr_t bstrpath{ path };
    _variant_t breadOnly{ readOnly };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Open(bstrpath, breadOnly, passwd, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

IAcadDocuments* PyIAcadDocumentsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDocuments*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyAcadApplicationImpl
PyAcadApplicationImpl::PyAcadApplicationImpl()
    : m_pimpl(acedGetIDispatch(FALSE))
{
}

PyAcadApplicationImpl::PyAcadApplicationImpl(IAcadApplication* ptr)
    : m_pimpl(ptr)
{
}

void PyAcadApplicationImpl::Eval(const CString& csVal) const
{
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->Eval(bstrVal));
}

PyIAcadStateImplPtr PyAcadApplicationImpl::GetAcadState()
{
    IAcadState* ptr = nullptr;
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->GetZcadState(&ptr));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->GetAcadState(&ptr));
#else
    PyThrowBadHr(impObj()->GetAcadState(&ptr));
#endif
    return std::make_unique<PyIAcadStateImpl>(ptr);
}

wstringArray PyAcadApplicationImpl::ListArx()
{
    VARIANT rtVal;
    VariantInit(&rtVal);
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->ListZrx(&rtVal));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->ListGrx(&rtVal));
#else
    PyThrowBadHr(impObj()->ListArx(&rtVal));
#endif
    ULONG pcElem = 0;
    PWSTR* prgsz = nullptr;
    wstringArray vec;
    if (VariantToStringArrayAlloc(rtVal, &prgsz, &pcElem) == S_OK)
    {

        vec = wstringArray(prgsz, prgsz + pcElem);
        CoTaskMemFree(prgsz);
    }
    return vec;
}

void PyAcadApplicationImpl::LoadArx(const CString& csVal)
{
    _bstr_t bstrVal{ csVal };
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->LoadZrx(bstrVal));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->LoadGrx(bstrVal));
#else
    PyThrowBadHr(impObj()->LoadArx(bstrVal));
#endif
}

void PyAcadApplicationImpl::LoadDVB(const CString& csVal)
{
#if defined(_ZRXTARGET)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->LoadDVB(bstrVal));
#endif
}

void PyAcadApplicationImpl::Quit()
{
    PyThrowBadHr(impObj()->Quit());
}

void PyAcadApplicationImpl::RunMacro(const CString& csVal)
{
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->RunMacro(bstrVal));
}

void PyAcadApplicationImpl::UnloadArx(const CString& csVal)
{
    _bstr_t bstrVal{ csVal };
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->UnloadZrx(bstrVal));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->UnloadGrx(bstrVal));
#else
    PyThrowBadHr(impObj()->UnloadArx(bstrVal));
#endif
}

void PyAcadApplicationImpl::UnloadDVB(const CString& csVal)
{
#if defined(_ZRXTARGET)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->UnloadDVB(bstrVal));
#endif
}

void PyAcadApplicationImpl::Update()
{
    PyThrowBadHr(impObj()->Update());
}

void PyAcadApplicationImpl::ZoomAll()
{
    PyThrowBadHr(impObj()->ZoomAll());
}

void PyAcadApplicationImpl::ZoomCenter(const AcGePoint3d& pnt, double magnify)
{
    VARIANT rtVal;
    VariantInit(&rtVal);
    constexpr ULONG s = sizeof(pnt) / sizeof(double);
    PyThrowBadHr(InitVariantFromDoubleArray(asDblArray(pnt), s, &rtVal));
    PyThrowBadHr(impObj()->ZoomCenter(rtVal, magnify));
}

void PyAcadApplicationImpl::ZoomExtents()
{
    PyThrowBadHr(impObj()->ZoomExtents());
}

void PyAcadApplicationImpl::ZoomPickWindow()
{
    PyThrowBadHr(impObj()->ZoomPickWindow());
}

void PyAcadApplicationImpl::ZoomPrevious()
{
    PyThrowBadHr(impObj()->ZoomPickWindow());
}

void PyAcadApplicationImpl::ZoomScaled(double magnify, PyAcZoomScaleType scaletype)
{
    AcZoomScaleType _scaletype = (AcZoomScaleType)scaletype;
    PyThrowBadHr(impObj()->ZoomScaled(magnify, _scaletype));
}

PyIAcadDocumentPtr PyAcadApplicationImpl::GetActiveDocument() const
{
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveDocument(&ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

void PyAcadApplicationImpl::SetActiveDocument(const PyIAcadDocumentImpl& val) const
{
    PyThrowBadHr(impObj()->put_ActiveDocument(val.impObj()));
}

CString PyAcadApplicationImpl::GetCaption() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Caption(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

PyIAcadDocumentsPtr PyAcadApplicationImpl::GetDocuments() const
{
    IAcadDocuments* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Documents(&ptr));
    return std::make_unique<PyIAcadDocumentsImpl>(ptr);
}

CString PyAcadApplicationImpl::GetFullName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_FullName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

int PyAcadApplicationImpl::GetHeight() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_Height(&val));
    return val;
}

void PyAcadApplicationImpl::SetHeight(int val)
{
    PyThrowBadHr(impObj()->put_Height(val));
}

LONG_PTR PyAcadApplicationImpl::GetHWND() const
{
    LONG_PTR val = 0;
    PyThrowBadHr(impObj()->get_HWND(&val));
    return val;
}

long PyAcadApplicationImpl::GetLocaleId() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_LocaleId(&val));
    return val;
}

PyIAcadMenuBarPtr PyAcadApplicationImpl::GetMenuBar() const
{
    IAcadMenuBar* ptr = nullptr;
    PyThrowBadHr(impObj()->get_MenuBar(&ptr));
    return std::make_unique<PyIAcadMenuBarImpl>(ptr);
}

PyIAcadMenuGroupsPtr PyAcadApplicationImpl::GetMenuGroups() const
{
    IAcadMenuGroups* ptr = nullptr;
    PyThrowBadHr(impObj()->get_MenuGroups(&ptr));
    return std::make_unique<PyIAcadMenuGroupsImpl>(ptr);
}

CString PyAcadApplicationImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyAcadApplicationImpl::GetPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Path(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

PyIAcadPreferencesPtr PyAcadApplicationImpl::GetPreferences()
{
    IAcadPreferences* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Preferences(&ptr));
    return std::make_unique<PyIAcadPreferencesImpl>(ptr);
}

CString PyAcadApplicationImpl::GetVersion() const
{
    _bstr_t bstrVal;
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadHr(impObj()->get_Version(&bstrVal.GetBSTR()));
#endif
    return (LPCTSTR)bstrVal;
}

bool PyAcadApplicationImpl::GetVisible() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Visible(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyAcadApplicationImpl::SetVisible(bool val)
{
    VARIANT_BOOL rtVal = val ? VARIANT_TRUE : VARIANT_FALSE;
    PyThrowBadHr(impObj()->put_Visible(rtVal));
}

int PyAcadApplicationImpl::GetWidth() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_Width(&val));
    return val;
}

void PyAcadApplicationImpl::SetWidth(int val)
{
    PyThrowBadHr(impObj()->put_Width(val));
}

int PyAcadApplicationImpl::GetWindowLeft() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_WindowLeft(&val));
    return val;
}

void PyAcadApplicationImpl::SetWindowLeft(int val)
{
    PyThrowBadHr(impObj()->put_WindowLeft(val));
}

PyAcWindowState PyAcadApplicationImpl::GetWindowState() const
{
    AcWindowState val = (AcWindowState)PyAcWindowState::pyacNorm;
    PyThrowBadHr(impObj()->get_WindowState(&val));
    return (PyAcWindowState)val;
}

void PyAcadApplicationImpl::SetWindowState(PyAcWindowState val)
{
    PyThrowBadHr(impObj()->put_WindowState(AcWindowState(val)));
}

int PyAcadApplicationImpl::GetWindowTop() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_WindowTop(&val));
    return val;
}

void PyAcadApplicationImpl::SetWindowTop(int val)
{
    PyThrowBadHr(impObj()->put_WindowTop(val));
}

bool PyAcadApplicationImpl::runTest(const AcDbObjectId& id)
{
    AcAxDocLock lock;
    return true;
}

IAcadApplication* PyAcadApplicationImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadApplication*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//IAcadUtilityImpl
PyIAcadUtilityImpl::PyIAcadUtilityImpl(IAcadUtility* ptr)
    : m_pimpl(ptr)
{
}

IAcadUtility* PyIAcadUtilityImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadUtility*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSecurityParamsImpl
PyIAcadSecurityParamsImpl::PyIAcadSecurityParamsImpl(IAcadSecurityParams* ptr)
    : m_pimpl(ptr)
{
}

IAcadSecurityParams* PyIAcadSecurityParamsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSecurityParams*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSelectionSetImpl
PyIAcadSelectionSetImpl::PyIAcadSelectionSetImpl(IAcadSelectionSet* ptr)
    : m_pimpl(ptr)
{
}

IAcadSelectionSet* PyIAcadSelectionSetImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSelectionSet*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSecurityParamsImpl
PyIAcadSelectionSetsImpl::PyIAcadSelectionSetsImpl(IAcadSelectionSets* ptr)
    : m_pimpl(ptr)
{
}

IAcadSelectionSets* PyIAcadSelectionSetsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSelectionSets*>(m_pimpl.GetInterfacePtr());
}
