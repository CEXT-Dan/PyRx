#pragma once

#ifdef PYRXDEBUG

#pragma comment( lib , "propsys.lib" )

#if defined(_BRXTARGET) && (_BRXTARGET <= 250)
#import "axbricscaddb1.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "axbricscadapp1.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ARXTARGET) && (_ARXTARGET <= 243)
#import "acax24ENU.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ARXTARGET) && (_ARXTARGET == 250)
#import "acax25ENU.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ZRXTARGET) && (_ZRXTARGET == 240)
#import "zwcad21.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ZRXTARGET) && (_ZRXTARGET == 250)
#import "zwcad25.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_GRXTARGET) && (_GRXTARGET == 240)
#import "acax.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_GRXTARGET) && (_GRXTARGET == 250)
#import "acax.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ZRXTARGET)
#define IAcadApplicationPtr IZcadApplicationPtr
#define IAcadApplication IZcadApplication

#define IAcadDocumentPtr IZcadDocumentPtr
#define IAcadDocument IZcadDocument
#endif

#if defined(_GRXTARGET)
#define IAcadApplicationPtr IGcadApplicationPtr
#define IAcadApplication IGcadApplication

#define IAcadDocumentPtr IGcadDocumentPtr
#define IAcadDocument IGcadDocument
#endif

class PyAcadApplicationImpl
{
public:
    PyAcadApplicationImpl();
    ~PyAcadApplicationImpl() = default;
    void Eval(const CString& csVal) const;
    //AcadState GetAcadState();
    std::vector<std::wstring> ListArx();


    static bool runTest();
public:
    IAcadApplication* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadApplicationPtr m_pimpl;
};



#endif