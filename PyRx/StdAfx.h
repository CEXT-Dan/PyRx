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

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN			//- Exclude rarely-used stuff from Windows headers
#endif

//- Modify the following defines if you have to target a platform prior to the ones specified below.
//- Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER					//- Allow use of features specific to Windows 95 and Windows NT 4 or later.
#define WINVER 0x0601			//- Change this to the appropriate value to target Windows 98 and Windows 2000 or later.
#endif

#ifndef _WIN32_WINNT			//- Allow use of features specific to Windows NT 4 or later.
#define _WIN32_WINNT 0x0601		//- Change this to the appropriate value to target Windows 2000 or later.
#endif						

#ifndef _WIN32_WINDOWS			//- Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0610	//- Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE				//- Allow use of features specific to IE 4.0 or later.
#define _WIN32_IE 0x0601		//- Change this to the appropriate value to target IE 5.0 or later.
#endif


#define SETBIT(flags, bit, value) ((value) ? (flags |= (bit)) : (flags &= ~(bit)))
#define GETBIT(flags, bit) (((flags) & (bit)) ? true : false)


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
//#define _BREP_SUPPORT_			//- Support for the BRep API
//#define _HLR_SUPPORT_				//- Support for the Hidden Line Removal API
//#define _AMODELER_SUPPORT_		//- Support for the AModeler API
//#define _ASE_SUPPORT_				//- Support for the ASI/ASE API
//#define _RENDER_SUPPORT_			//- Support for the AutoCAD Render API
//#define _ARX_CUSTOM_DRAG_N_DROP_	//- Support for the ObjectARX Drag'n Drop API
//#define _INC_LEAGACY_HEADERS_		//- Include legacy headers in this project

#include "arxHeaders.h"
#include "axlock.h"

#define BOOST_PYTHON_STATIC_LIB
#define PY_SSIZE_T_CLEAN

#include <Python.h>
#pragma comment( lib , "python310.lib" )

#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>

#include "RxPyString.h"
#include "PyException.h"

//#define PyRxDebug

#ifdef GRXAPP
#pragma comment( lib , "gcad.lib" )
#pragma comment( lib , "gcbase.lib" )
#pragma comment( lib , "gcax.lib" )
#pragma comment( lib , "gcbr.lib" )
#pragma comment( lib , "gccore.lib" )
#pragma comment( lib , "gcdb.lib" )
#endif

#define SOLID3D_SUPPORT

#ifdef ARXAPP
#pragma comment( lib , "AcPal.lib" )
#ifdef SOLID3D_SUPPORT
#pragma comment( lib , "acgeoment.lib" )
#endif
#endif

static inline const AcString PyCommandPrefix = _T("PyRxCmd_");
static inline const AcString PyLispFuncPrefix = _T("PyRxLisp_");
static inline const AcString PyCommandFlagPrefix = _T("cmdflags=");

static inline constexpr const char* PyAppNamespace = "PyRxApp";
static inline constexpr const char* PyApNamespace = "PyAp";
static inline constexpr const char* PyRxNamespace = "PyRx";
static inline constexpr const char* PyGeNamespace = "PyGe";
static inline constexpr const char* PyDbNamespace = "PyDb";
static inline constexpr const char* PyGiNamespace = "PyGi";
static inline constexpr const char* PyEdNamespace = "PyEd";

static inline constexpr const wchar_t* PyAppNamespaceW = L"PyRxApp";
static inline constexpr const wchar_t* PyApNamespaceW = L"PyAp";
static inline constexpr const wchar_t* PyRxNamespaceW = L"PyRx";
static inline constexpr const wchar_t* PyGeNamespaceW = L"PyGe";
static inline constexpr const wchar_t* PyDbNamespaceW = L"PyDb";
static inline constexpr const wchar_t* PyGiNamespaceW = L"PyGi";
static inline constexpr const wchar_t* PyEdNamespaceW = L"PyEd";

//-----------------------------------------------------------------------------
#include "DocData.h" //- Your document specific data class holder

//- Declare it as an extern here so that it becomes available in all modules
extern AcApDataManager<CDocData> DocVars;

const TCHAR* getappname();

template<typename IteratorType>
constexpr auto makeIterator = [](const auto& record)
{
    IteratorType* pIter = nullptr;
    Acad::ErrorStatus es = record.newIterator(pIter);
    return std::make_tuple(es, std::unique_ptr<IteratorType>(pIter));
};
constexpr auto makeBlockTableIterator = makeIterator<AcDbBlockTableIterator>;
constexpr auto makeBlockTableRecordIterator = makeIterator<AcDbBlockTableRecordIterator>;


class PerfTimer
{
private:
    LARGE_INTEGER frequency{};
    LARGE_INTEGER t1{};
    LARGE_INTEGER t2{};
    double elapsedTime = 0;
public:
    PerfTimer(const CString& funcName);
    ~PerfTimer() = default;

private:
    void end();
private:
    CString m_funcName;
};

inline PerfTimer::PerfTimer(const CString& funcName)
    : m_funcName(funcName)
{
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&t1);
}

inline void PerfTimer::end()
{
    QueryPerformanceCounter(&t2);
    elapsedTime = (float)(t2.QuadPart - t1.QuadPart) / frequency.QuadPart;
    acutPrintf(_T("\n%ls %lf"), (const TCHAR*)m_funcName, elapsedTime);
}

//-------------------------------------------------------------------------------------
//AcResBufPtr
using AcResBufPtr = std::unique_ptr < resbuf, decltype([](resbuf* ptr) noexcept
{
    if (ptr != nullptr)
        acutRelRb(ptr);
}) > ;

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

// Import Python and wxPython headers
#define WXUSINGDLL
#define __WXMSW__ 
#include <wxPython/sip.h>
#include <wxPython/wxpy_api.h>
#include "WxUserInteraction.h"

class WxPyAutoLock
{
public:
    WxPyAutoLock()
    {
        if (canLock) [[likely]]
            blocked = wxPyBeginBlockThreads();
    }
    ~WxPyAutoLock()
    {
        if (canLock) [[likely]]
            wxPyEndBlockThreads(blocked);
    }

    WxPyAutoLock(const WxPyAutoLock&) = delete;
    WxPyAutoLock& operator=(const WxPyAutoLock&) = delete;

    wxPyBlock_t blocked{};
    inline static bool canLock = false;
};

struct PyAutoLockGIL
{

    PyAutoLockGIL()
    {
        if (canLock)[[likely]]
            gstate = PyGILState_Ensure();
    }

    ~PyAutoLockGIL()
    {
        if (canLock) [[likely]]
            PyGILState_Release(gstate);
    }

    PyAutoLockGIL(const PyAutoLockGIL&) = delete;
    PyAutoLockGIL& operator=(const PyAutoLockGIL&) = delete;

    PyGILState_STATE gstate{};
    inline static bool canLock = false;
};

struct PyObjectDeleter 
{
    void operator()(PyObject* ptr)
    {
        PyAutoLockGIL lock;
        Py_XDECREF(ptr);
    }
};
using PyObjectPtr = std::unique_ptr < PyObject, PyObjectDeleter>;


template<typename T>
inline std::vector< T > py_list_to_std_vector(const boost::python::object& iterable)
{
    PyAutoLockGIL lock;
    return std::vector< T >(boost::python::stl_input_iterator< T >(iterable),
        boost::python::stl_input_iterator< T >());
}

template <class T>
inline boost::python::list std_vector_to_py_list(std::vector<T> vector)
{
    PyAutoLockGIL lock;
    typename std::vector<T>::iterator iter;
    boost::python::list list;
    for (iter = vector.begin(); iter != vector.end(); ++iter) {
        list.append(*iter);
    }
    return list;
}

//TODO avoid copy
inline AcGePoint2dArray PyListToPoint2dArray(const boost::python::object& iterable)
{
    AcGePoint2dArray arr;
    auto vec = py_list_to_std_vector<AcGePoint2d>(iterable);
    for (auto& item : vec)
        arr.append(item);
    return arr;
}

//TODO avoid copy
inline AcGePoint3dArray PyListToPoint3dArray(const boost::python::object& iterable)
{
    AcGePoint3dArray arr;
    auto vec = py_list_to_std_vector<AcGePoint3d>(iterable);
    for (auto& item : vec)
        arr.append(item);
    return arr;
}

#pragma pack (pop)

