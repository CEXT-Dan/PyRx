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

#if defined(_ZRXTARGET) && (_ZRXTARGET <= 240)
#define _ZRXTARGET240 240
#endif

#if defined(_GRXTARGET) && (_GRXTARGET <= 240)
#define _GRXTARGET240 240
#endif

#if defined(_BRXTARGET) && (_BRXTARGET <= 240)
#define _BRXTARGET240 240
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
#include <array>
#include <mutex>
#include <unordered_map>
#include <unordered_set>

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

#include <Python.h>
#pragma comment( lib , "python312.lib" )

#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>
#include <boost/functional/hash.hpp>

#include "RxPyString.h"
#include "PyException.h"

#ifdef PYRXDEBUG
#define PYRX_IN_PROGRESS_GS_GI
//#define PYRX_IN_PROGRESS_INPLACE_TEXT_EDITOR not in BRX
#endif


#if defined(_ARXTARGET)
#pragma comment( lib , "AcPal.lib" )
#pragma comment( lib , "acgeoment.lib" )
#pragma comment( lib , "AcPublish_crx.lib" )
#pragma comment( lib , "AcMPolygonObj.lib" )
#pragma comment( lib , "AcDbPointCloudObj.lib" )
#pragma comment( lib , "AcGeolocationObj.lib" )
#pragma comment( lib , "AcDrawBridge.lib" )
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
#pragma comment( lib , "ZwGs.lib" )
#endif

static inline const AcString PyCommandPrefix = _T("PyRxCmd_");
static inline const AcString PyLispFuncPrefix = _T("PyRxLisp_");
static inline const AcString PyCommandFlagPrefix = _T("cmdflags=");

static inline constexpr const char* PyApNamespace = "PyAp";
static inline constexpr const char* PyRxNamespace = "PyRx";
static inline constexpr const char* PyGeNamespace = "PyGe";
static inline constexpr const char* PyGsNamespace = "PyGs";
static inline constexpr const char* PyDbNamespace = "PyDb";
static inline constexpr const char* PyGiNamespace = "PyGi";
static inline constexpr const char* PyEdNamespace = "PyEd";
static inline constexpr const char* PyPlNamespace = "PyPl";
static inline constexpr const char* PyBrxCvNamespace = "PyBrxCv";


static inline constexpr const wchar_t* PyAppNamespaceW = L"PyRxApp";
static inline constexpr const wchar_t* PyApNamespaceW = L"PyAp";
static inline constexpr const wchar_t* PyRxNamespaceW = L"PyRx";
static inline constexpr const wchar_t* PyGeNamespaceW = L"PyGe";
static inline constexpr const wchar_t* PyGsNamespaceW = L"PyGs";
static inline constexpr const wchar_t* PyDbNamespaceW = L"PyDb";
static inline constexpr const wchar_t* PyGiNamespaceW = L"PyGi";
static inline constexpr const wchar_t* PyEdNamespaceW = L"PyEd";
static inline constexpr const wchar_t* PyPlNamespaceW = L"PyPl";
static inline constexpr const wchar_t* PyBrxCvNamespaceW = L"PyBrxCv";

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
constexpr auto makeAcDbSymbolTableIterator = makeIterator<AcDbSymbolTableIterator>;
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
#include <wxPython/sip.h>
#include <wxPython/wxpy_api.h>
#include "PyDocString.h"


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

    wxPyBlock_t blocked = PyGILState_UNLOCKED;
    inline static bool canLock = false;
};

struct PyAutoLockGIL
{
    PyAutoLockGIL()
    {
        if (canLock) [[likely]]
            gstate = PyGILState_Ensure();
    }

    ~PyAutoLockGIL()
    {
        if (canLock) [[likely]]
            PyGILState_Release(gstate);
    }

    PyAutoLockGIL(const PyAutoLockGIL&) = delete;
    PyAutoLockGIL& operator=(const PyAutoLockGIL&) = delete;

    PyGILState_STATE gstate = PyGILState_UNLOCKED;
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
using PyObjectPtr = std::unique_ptr <PyObject, PyObjectDeleter>;


inline AcGePoint3d py_list_to_point3d(const boost::python::object& iterable)
{
    PyAutoLockGIL lock;
    auto vec = std::vector<double>(boost::python::stl_input_iterator<double>(iterable),
        boost::python::stl_input_iterator<double>());
    if (vec.size() >= 3)
        return AcGePoint3d(vec[0], vec[1], vec[2]);
    else if (vec.size() == 2)
        return AcGePoint3d(vec[0], vec[1], 0.0);
    else
        throw PyAcadErrorStatus(eInvalidInput);
}

inline AcGePoint2d py_list_to_point2d(const boost::python::object& iterable)
{
    PyAutoLockGIL lock;
    auto vec = std::vector<double>(boost::python::stl_input_iterator<double>(iterable),
        boost::python::stl_input_iterator<double>());
    if (vec.size() < 2)
        throw PyAcadErrorStatus(eInvalidInput);
    return AcGePoint2d(vec[0], vec[1]);
}

inline AcGeVector3d py_list_to_vector3d(const boost::python::object& iterable)
{
    PyAutoLockGIL lock;
    auto vec = std::vector<double>(boost::python::stl_input_iterator<double>(iterable),
        boost::python::stl_input_iterator<double>());
    if (vec.size() < 3)
        throw PyAcadErrorStatus(eInvalidInput);
    return AcGeVector3d(vec[0], vec[1], vec[2]);
}

inline AcGeVector2d py_list_to_vector2d(const boost::python::object& iterable)
{
    PyAutoLockGIL lock;
    auto vec = std::vector<double>(boost::python::stl_input_iterator<double>(iterable),
        boost::python::stl_input_iterator<double>());
    if (vec.size() < 2)
        throw PyAcadErrorStatus(eInvalidInput);
    return AcGeVector2d(vec[0], vec[1]);
}

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
    boost::python::list list;
    typename std::vector<T>::iterator iter;
    for (iter = vector.begin(); iter != vector.end(); ++iter)
        list.append(*iter);
    return list;
}

inline boost::python::list IntArrayToPyList(const AcDbIntArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (auto item : arr)
        pyPyList.append(item);
    return pyPyList;
}

inline boost::python::list Int32ArrayToPyList(const AcArray<Adesk::Int32>& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (auto item : arr)
        pyPyList.append(item);
    return pyPyList;
}

inline boost::python::list IntU64ArrayToPyList(const AcArray<Adesk::UInt64>& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (auto item : arr)
        pyPyList.append(item);
    return pyPyList;
}

inline boost::python::list DoubleArrayToPyList(const AcGeDoubleArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (auto item : arr)
        pyPyList.append(item);
    return pyPyList;
}

inline boost::python::list Point3dArrayToPyList(const AcGePoint3dArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (const auto& item : arr)
        pyPyList.append(item);
    return pyPyList;
}

inline boost::python::list Vector3dArrayToPyList(const AcGeVector3dArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (const auto& item : arr)
        pyPyList.append(item);
    return pyPyList;
}

inline boost::python::list Point2dArrayToPyList(const AcGePoint2dArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (const auto& item : arr)
        pyPyList.append(item);
    return pyPyList;
}

inline boost::python::list AcStringArrayToPyList(const AcStringArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyPyList;
    for (const auto& item : arr)
        pyPyList.append(wstr_to_utf8(item).c_str());
    return pyPyList;
}

//TODO avoid copy
inline AcGeDoubleArray PyListToDoubleArray(const boost::python::object& iterable)
{
    const auto& vec = py_list_to_std_vector<double>(iterable);
    AcGeDoubleArray arr;
    arr.setPhysicalLength(vec.size());
    for (const auto& item : vec)
        arr.append(item);
    return arr;
}

inline AcGePoint2dArray PyListToPoint2dArray(const boost::python::object& iterable)
{
    const auto& vec = py_list_to_std_vector<AcGePoint2d>(iterable);
    AcGePoint2dArray arr;
    arr.setPhysicalLength(vec.size());
    for (const auto& item : vec)
        arr.append(item);
    return arr;
}

inline AcGePoint3dArray PyListToPoint3dArray(const boost::python::object& iterable)
{
    const auto& vec = py_list_to_std_vector<AcGePoint3d>(iterable);
    AcGePoint3dArray arr;
    arr.setPhysicalLength(vec.size());
    for (const auto& item : vec)
        arr.append(item);
    return arr;
}

inline AcGeVector3dArray PyListToVector3dArray(const boost::python::object& iterable)
{
    const auto& vec = py_list_to_std_vector<AcGeVector3d>(iterable);
    AcGeVector3dArray arr;
    arr.setPhysicalLength(vec.size());
    for (const auto& item : vec)
        arr.append(item);
    return arr;
}

inline AcGeVector2dArray PyListToVector2dArray(const boost::python::object& iterable)
{
    const auto& vec = py_list_to_std_vector<AcGeVector2d>(iterable);
    AcGeVector2dArray arr;
    arr.setPhysicalLength(vec.size());
    for (const auto& item : vec)
        arr.append(item);
    return arr;
}

inline AcArray<int> PyListToIntArray(const boost::python::object& iterable)
{
    const auto& vec = py_list_to_std_vector<int>(iterable);
    AcArray<int> arr;
    arr.setPhysicalLength(vec.size());
    for (const auto& item : vec)
        arr.append(item);
    return arr;
}

inline AcArray<Adesk::Int32> PyListToInt32Array(const boost::python::object& iterable)
{
    const auto& vec = py_list_to_std_vector<Adesk::Int32>(iterable);
    AcArray<Adesk::Int32> arr;
    arr.setPhysicalLength(vec.size());
    for (const auto& item : vec)
        arr.append(item);
    return arr;
}

inline AcArray<Adesk::UInt64> PyListToUInt64Array(const boost::python::object& iterable)
{
    const auto& vec = py_list_to_std_vector<Adesk::UInt64>(iterable);
    AcArray<Adesk::UInt64> arr;
    arr.setPhysicalLength(vec.size());
    for (const auto& item : vec)
        arr.append(item);
    return arr;
}

inline AcStringArray PyListAcStringArray(const boost::python::object& iterable)
{
    const auto& vec = py_list_to_std_vector<std::string>(iterable);
    AcStringArray arr;
    arr.setPhysicalLength(vec.size());
    for (const auto& item : vec)
        arr.append(utf8_to_wstr(item).c_str());
    return arr;
}
#pragma pack (pop)

