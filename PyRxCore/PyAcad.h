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
#define AcWindowState   ZcWindowState
#define AcColorMethod   ZcColorMethod
#define AcColor         ZcColor
//

#define IAcadApplicationPtr IZcadApplicationPtr
#define IAcadApplication IZcadApplication
#define IAcadDocumentsPtr IZcadDocumentsPtr
#define IAcadDocuments IZcadDocuments
#define IAcadDatabasePtr IZcadDatabasePtr
#define IAcadDatabase IZcadDatabase
#define IAcadDocumentPtr IZcadDocumentPtr
#define IAcadDocument IZcadDocument
#define IAcadStatePtr IZcadStatePtr
#define IAcadState IZcadState
#define IAcadObjectPtr IZcadObjectPtr
#define IAcadObject IZcadObject
#define IAcadEntityPtr IZcadEntityPtr
#define IAcadEntity IZcadEntity
#define IAcadAcCmColorPtr IZcadZcCmColorPtr
#define IAcadAcCmColor IZcadZcCmColor
#define IAcadHyperlinkPtr IZcadHyperlinkPtr
#define IAcadHyperlink IZcadHyperlink
#define IAcadHyperlinksPtr IZcadHyperlinksPtr
#define IAcadHyperlinks IZcadHyperlinks
#endif

#if defined(_GRXTARGET)
// enums
#define AcZoomScaleType GcZoomScaleType
//#define AcWindowState   GcWindowState
#define AcColorMethod   GcColorMethod
#define AcColor         GcColor
//

#define IAcadApplicationPtr IGcadApplicationPtr
#define IAcadApplication IGcadApplication
#define IAcadDatabasePtr IGcadDatabasePtr
#define IAcadDatabase IGcadDatabase
#define IAcadDocumentsPtr IGcadDocumentsPtr
#define IAcadDocuments IGcadDocuments
#define IAcadDocumentPtr IGcadDocumentPtr
#define IAcadDocument IGcadDocument
#define IAcadStatePtr IGcadStatePtr
#define IAcadState IGcadState
#define IAcadObjectPtr IGcadObjectPtr
#define IAcadObject IGcadObject
#define IAcadEntityPtr IGcadEntityPtr
#define IAcadEntity IGcadEntity
#define IAcadAcCmColorPtr IGcadGcCmColorPtr
#define IAcadAcCmColor IGcadGcCmColor
#define IAcadHyperlinkPtr IGcadHyperlinkPtr
#define IAcadHyperlink IGcadHyperlink
#define IAcadHyperlinksPtr IGcadHyperlinksPtr
#define IAcadHyperlinks IGcadHyperlinks
#endif

#endif