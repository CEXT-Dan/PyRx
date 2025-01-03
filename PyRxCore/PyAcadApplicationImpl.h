#pragma once

#ifdef PYRXDEBUG

#include <atlbase.h>
#include <atlsafe.h>

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
// enums
#define AcZoomScaleType ZcZoomScaleType
//

#define IAcadApplicationPtr IZcadApplicationPtr
#define IAcadApplication IZcadApplication

#define IAcadDocumentPtr IZcadDocumentPtr
#define IAcadDocument IZcadDocument
#endif

#if defined(_GRXTARGET)
// enums
#define AcZoomScaleType GcZoomScaleType
//

#define IAcadApplicationPtr IGcadApplicationPtr
#define IAcadApplication IGcadApplication

#define IAcadDocumentPtr IGcadDocumentPtr
#define IAcadDocument IGcadDocument
#endif

using wstringArray = std::vector<std::wstring>;

class PyAcadApplicationImpl
{
public:
    PyAcadApplicationImpl();
    ~PyAcadApplicationImpl() = default;
    void                    Eval(const CString& csVal) const;
    //AcadState             GetAcadState();
    wstringArray            ListArx();
    void                    LoadArx(const CString& csVal);
    void                    LoadDVB(const CString& csVal);
    void                    Quit();
    void                    RunMacro(const CString& csVal);
    void                    UnloadArx(const CString& csVal);
    void                    UnloadDVB(const CString& csVal);
    void                    Update();
    //void                    Zoom(int ...);
    void                    ZoomAll();
    void                    ZoomCenter(const AcGePoint3d& pnt, double magnify);
    void                    ZoomExtents();
    void                    ZoomPickWindow();
    void                    ZoomPrevious();
    void                    ZoomScaled(double magnify, AcZoomScaleType scaletype);
    //--properties
    //ActiveDocument
    //Caption
    //Documents
    //FullName
    //Height
    //HWND
    //LocaleId
    //MenuBar
    //MenuGroups
    //Name
    //Path
    //Preferences
    //StatusId
    //Version
    //Visible
    //Width
    //WindowLeft
    //WindowState 
    //WindowTop
    static bool             runTest();
public:
    IAcadApplication* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadApplicationPtr m_pimpl;
};



#endif