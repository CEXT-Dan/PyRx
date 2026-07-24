// (C) Copyright 2002-2007 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//- StdAfx.h : include file for standard system include files,
//-      or project specific include files that are used frequently,
//-      but are changed infrequently
//-----------------------------------------------------------------------------
#pragma once

#pragma pack (push, 8)
#pragma warning(disable: 4786 4996 26812)

//#pragma warning(disable: 4098)

//-----------------------------------------------------------------------------
#define STRICT
#define NOMINMAX

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN 
#endif

#ifndef WINVER
#define WINVER _WIN32_WINNT_WIN10
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT _WIN32_WINNT_WIN10
#endif

#ifndef _WIN32_IE
#define _WIN32_IE 0x0A00
#endif

#define SETBIT(flags, bit, value) ((value) ? (flags |= (bit)) : (flags &= ~(bit)))
#define GETBIT(flags, bit) (((flags) & (bit)) ? true : false)

//TODO: rename these to imply up to version 
#if defined(_ZRXTARGET) && (_ZRXTARGET <= 240)
#define _ZRXTARGET240 240
#endif
#if defined(_ZRXTARGET) && (_ZRXTARGET <= 250)
#define _ZRXTARGET250 250
#endif
#if defined(_ZRXTARGET) && (_ZRXTARGET <= 260)
#define _ZRXTARGET260 260
#endif
#if defined(_ZRXTARGET) && (_ZRXTARGET <= 270)
#define _ZRXTARGET270 270
#endif

#if defined(_GRXTARGET) && (_GRXTARGET <= 240)
#define _GRXTARGET240 250
#endif
#if defined(_GRXTARGET) && (_GRXTARGET <= 250)
#define _GRXTARGET250 250
#endif
#if defined(_GRXTARGET) && (_GRXTARGET <= 260)
#define _GRXTARGET260 260
#endif
#if defined(_GRXTARGET) && (_GRXTARGET <= 270)
#define _GRXTARGET270 270
#endif

#if defined(_BRXTARGET) && (_BRXTARGET <= 240)
#define _BRXTARGET240 240
#endif
#if defined(_BRXTARGET) && (_BRXTARGET <= 250)
#define _BRXTARGET250 250
#endif
#if defined(_BRXTARGET) && (_BRXTARGET <= 260)
#define _BRXTARGET260 260
#endif
#if defined(_BRXTARGET) && (_BRXTARGET <= 270)
#define _BRXTARGET270 270
#endif

#if defined(_ARXTARGET) && (_ARXTARGET <= 243)
#define _ARXTARGET240 240
#endif
#if defined(_ARXTARGET) && (_ARXTARGET == 251)
#define _ARXTARGET250 250
#endif
#if defined(_ARXTARGET) && (_ARXTARGET <= 260)
#define _ARXTARGET260 260
#endif

//- ObjectARX and OMF headers needs this
#include <map>
#include <vector>
#include <array>
#include <functional>
#include <memory>
#include <variant>
#include <string>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include <format>
#include <set>
#include <span>
#include <mutex>
#include <unordered_map>
#include <unordered_set>
#include <cwctype>
#include <ranges>
#include <queue>
#include <execution>
#include <numbers>

//-----------------------------------------------------------------------------
#include <afxwin.h>				//- MFC core and standard components
#include <afxext.h>				//- MFC extensions

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>				//- MFC OLE classes
#include <afxodlgs.h>			//- MFC OLE dialog classes
#include <afxdisp.h>			//- MFC Automation classes
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>				//- MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>				//- MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#include <afxdtctl.h>			//- MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>				//- MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

//-----------------------------------------------------------------------------
//- Include ObjectDBX/ObjectARX headers
//- Uncomment one of the following lines to bring a given library in your project.
#define _BREP_SUPPORT_			//- Support for the BRep API
//#define _HLR_SUPPORT_				//- Support for the Hidden Line Removal API
//#define _AMODELER_SUPPORT_		//- Support for the AModeler API
//#define _ASE_SUPPORT_				//- Support for the ASI/ASE API
//#define _RENDER_SUPPORT_			//- Support for the AutoCAD Render API
#define _ARX_CUSTOM_DRAG_N_DROP_	//- Support for the ObjectARX Drag'n Drop API
//#define _INC_LEAGACY_HEADERS_		//- Include legacy headers in this project

#include "arxHeaders.h"
#include "axlock.h"

#define BOOST_PYTHON_STATIC_LIB
#define PY_SSIZE_T_CLEAN

#if !defined (_MSC_PLATFORM_TOOLSET)
#pragma message ("_MSC_PLATFORM_TOOLSET is not defined!!!")
#endif

//for PyApApplication::hostFullVersion
#pragma comment( lib , "version.lib" )

// python
#include <Python.h>

// boost
#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>
#include <boost/functional/hash.hpp>

// us
#include "RxPyString.h"
#include "PyException.h"
#include "Utilities.h"


#ifdef PYRXDEBUG
#define PYRX_IN_PROGRESS_GS_GI 
//#define PYRX_IN_PROGRESS
//#define PYRX_IN_PROGRESS_INPLACE_TEXT_EDITOR not in BRX
#endif

#ifdef PYRXDEBUG
//#define WXMSWWINDOWPROC 1
#endif

#if defined(_ARXTARGET)
#pragma comment( lib , "AcPal.lib" )
#pragma comment( lib , "acgeoment.lib" )
#pragma comment( lib , "AcPublish_crx.lib" )
#pragma comment( lib , "AcMPolygonObj.lib" )
#pragma comment( lib , "AcDbPointCloudObj.lib" )
#pragma comment( lib , "AcGeolocationObj.lib" )
#pragma comment( lib , "AcDrawBridge.lib" )
#pragma comment( lib , "AdImaging.lib" )
#pragma comment( lib , "AdIntImgServices.lib" )
#pragma comment( lib , "axdb.lib" )
#endif

#if defined(_BRXTARGET)
using AcDbIntArray = AcArray<int>;
#include "AcGi.h"
#pragma comment( lib , "Ice.lib" )
#endif

#if defined(_BRXTARGET) && (_BRXTARGET == 240)
#pragma comment( lib , "BrxATIL24.lib" )
#elif defined(_BRXTARGET) && (_BRXTARGET == 250)
#pragma comment( lib , "BrxATIL25.lib" )
#elif defined(_BRXTARGET) && (_BRXTARGET == 260)
#pragma comment( lib , "BrxATIL26.lib" )
#elif defined(_BRXTARGET) && (_BRXTARGET == 270)
#pragma comment( lib , "BrxATIL27.lib" )
#endif

#if defined(_GRXTARGET)
#pragma comment( lib , "gcad.lib" )
#pragma comment( lib , "gcbase.lib" )
#pragma comment( lib , "gcbr.lib" )
#pragma comment( lib , "gccore.lib" )
#pragma comment( lib , "gcdb.lib" )
#pragma comment( lib , "GcDbConstraints.lib" )
#pragma comment( lib , "GcDbPointCloudObj.lib" )
#pragma comment( lib , "gcdyn.lib" )
#pragma comment( lib , "GcGeolocationObj.lib" )
#pragma comment( lib , "gcgs.lib" )
#pragma comment( lib , "GcHlrApi.lib" )
#pragma comment( lib , "GcImaging.lib" )
#pragma comment( lib , "GcModelDocObj.lib" )
#pragma comment( lib , "gplot.lib" )
#pragma comment( lib , "gcax.lib" )
#endif

#if defined(_ZRXTARGET)
#pragma comment( lib , "ZwAuto.lib" )
#pragma comment( lib , "ZwBase.lib" )
#pragma comment( lib , "ZWCAD.lib" )
#pragma comment( lib , "ZwDatabase.lib" )
#pragma comment( lib , "ZwdUI.lib" )
#pragma comment( lib , "ZwGeometry.lib" )
#pragma comment( lib , "ZwGs.lib" )
#pragma comment( lib , "ZwPAL.lib" )

#if defined(_ZRXTARGET) && (_ZRXTARGET > 240)
#pragma comment( lib , "ZwPointCloudCore.lib" )
#endif

#pragma comment( lib , "ZwRx.lib" )
#pragma comment( lib , "ZwTc.lib" )
#pragma comment( lib , "ZwUI.lib" )
#pragma comment( lib , "ZwZrx.lib" )
#pragma comment( lib , "ZwImaging.lib")
#endif

static inline const AcString PyCommandPrefix = _T("PyRxCmd_");
static inline const AcString PyLispFuncPrefix = _T("PyRxLisp_");
static inline const AcString PyCommandFlagPrefix = _T("cmdflags=");

constexpr const char* PyApNamespace = "PyAp";
constexpr const char* PyAxNamespace = "PyAx";
constexpr const char* PyRxNamespace = "PyRx";
constexpr const char* PyGeNamespace = "PyGe";
constexpr const char* PyGsNamespace = "PyGs";
constexpr const char* PyDbNamespace = "PyDb";
constexpr const char* PyGiNamespace = "PyGi";
constexpr const char* PyEdNamespace = "PyEd";
constexpr const char* PyPlNamespace = "PyPl";
constexpr const char* PySmNamespace = "PySm";
constexpr const char* PyBrNamespace = "PyBr";
constexpr const char* PyBrxNamespace = "PyBrx";
constexpr const char* PyBrxCvNamespace = "PyBrxCv";
constexpr const char* PyBrxBimNamespace = "PyBrxBim";

constexpr const bool py_show_user_defined = true;
constexpr const bool py_show_py_signatures = true;
constexpr const bool py_show_cpp_signatures = true;

//-----------------------------------------------------------------------------
#include "DocData.h" //- Your document specific data class holder

//- Declare it as an extern here so that it becomes available in all modules
extern AcApDataManager<CDocData> DocVars;

const TCHAR* getappname();
const AcString getPyRxBuldVersion();

constexpr auto makeBlockRefIterator = [](const AcDbBlockTableRecord& record)
    {
        AcDbBlockReferenceIdIterator* pIter = nullptr;
        Acad::ErrorStatus es = record.newBlockReferenceIdIterator(pIter);
        return std::make_tuple(es, std::unique_ptr<AcDbBlockReferenceIdIterator>(pIter));
    };

template<typename IteratorType>
constexpr auto makeIterator = [](const auto& record)
    {
        IteratorType* pIter = nullptr;
        Acad::ErrorStatus es = record.newIterator(pIter);
        return std::make_tuple(es, std::unique_ptr<IteratorType>(pIter));
    };
constexpr auto makeAcDbSymbolTableIterator = makeIterator<AcDbSymbolTableIterator>;
constexpr auto makeBlockTableIterator = makeIterator<AcDbBlockTableIterator>;
constexpr auto makeBlockTableRecordIterator = makeIterator<AcDbBlockTableRecordIterator>;

using AcEdCommandIteratorPtr = std::unique_ptr<AcEdCommandIterator>;

//Python does not have int16_t, used often in sysvars
constexpr bool isInt16_t(int32_t val) noexcept
{
    return val >= std::numeric_limits<int16_t>::min() &&
        val <= std::numeric_limits<int16_t>::max();
}

//-------------------------------------------------------------------------------------
//AcResBufPtr
using AcResBufPtr = std::unique_ptr < resbuf, decltype([](resbuf* p) noexcept { acutRelRb(p); }) > ;

//-------------------------------------------------------------------------------------
//AcDbObjectUPtr
template<typename T>
using AcDbObjectUPtr = std::unique_ptr < T, decltype([](T* ptr) noexcept
    {
        if (ptr != nullptr)
        {
            if (!ptr->objectId().isNull())
                ptr->close();
            else
                delete ptr;
        }
    }) > ;

using AcDbEntityUPtr = AcDbObjectUPtr<AcDbEntity>;
using AcDbAcDbPolylineUPtr = AcDbObjectUPtr<AcDbPolyline>;
using AcDbObjectIteratorUPtr = std::unique_ptr<AcDbObjectIterator>;

//-------------------------------------------------------------------------------------
//AcDbObjectPointer
using AcDbAttributePointer = AcDbObjectPointer<AcDbAttribute>;

//-------------------------------------------------------------------------------------
// Import Python and wxPython headers
#include <wxPython/sip.h>
#include <wxPython/wxpy_api.h>
#include "PyDocString.h"

//-------------------------------------------------------------------------------------
// PyAutoLockGIL
struct PyAutoLockGIL
{
    PyAutoLockGIL() noexcept
    {
        if (canLock) [[likely]]
            gstate = PyGILState_Ensure();
    }

    ~PyAutoLockGIL() noexcept
    {
        if (canLock) [[likely]]
            PyGILState_Release(gstate);
    }

    PyAutoLockGIL(const PyAutoLockGIL&) = delete;
    PyAutoLockGIL& operator=(const PyAutoLockGIL&) = delete;

    //members 
    PyGILState_STATE gstate = PyGILState_UNLOCKED;
    inline static bool canLock = false;
};

//-------------------------------------------------------------------------------------
// PyObjectPtr
inline void PyDecRef(PyObject* ptr) noexcept
{
    if (PyAutoLockGIL::canLock)
    {
        PyAutoLockGIL lock;
        Py_XDECREF(ptr);
    }
}

using PyObjectPtr = std::unique_ptr < PyObject, decltype([](PyObject* ptr) noexcept
    {
        PyDecRef(ptr);
    }) > ;

//---------------------------------------------------------------------------------------- -
//PySharedObjectDeleter
template<typename T>
struct PySharedObjectDeleter
{
    inline PySharedObjectDeleter(bool autoDelete)
        : m_autoDelete(autoDelete)
    {
    }

    inline void operator()(T* p) const
    {
        if (m_autoDelete)
            delete p;
    }
    bool m_autoDelete = true;
};

//-----------------------------------------------------------------------------------
//vector_indexing_suite
inline bool operator == (const AcGiPixelBGRA32& lhs, const AcGiPixelBGRA32& rhs) noexcept
{
    return std::addressof(lhs) == std::addressof(rhs);
}

typedef std::vector<AcGiPixelBGRA32> PyGiPixelBGRA32Array;
typedef std::vector<AcGePoint2d> PyGePoint2dArray;
typedef std::vector<AcGePoint3d> PyGePoint3dArray;
typedef AcArray<AcRxClass*> AcRxClassArray;

//PCH
#include "PyConverter.h"
#include "PyRxObject.h"
#include "PyDbObject.h"
#include "PyDbEntity.h"
#include "PyDbCurve.h"
#include "PyDbObjectId.h"
#include "PyDbSymbolTableRecord.h"

//Ge
#include "PyGeEntity3d.h"
#include "PyGeEntity2d.h"
#include "PyGeCurve3d.h"
#include "PyGeCurve2d.h"
//

#pragma pack (pop)
