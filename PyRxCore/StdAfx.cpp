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
//------ StdAfx.cpp : source file that includes just the standard includes
//------  StdAfx.pch will be the pre-compiled header
//------  StdAfx.obj will contain the pre-compiled type information
//-----------------------------------------------------------------------------
#include "StdAfx.h"

//TODO move these?
const TCHAR* getappname()
{
#ifdef _ZRXTARGET 
    return L"ZRX";
#endif
#ifdef _GRXTARGET 
    return L"GRX";
#endif
#ifdef _BRXTARGET 
    return L"BRX";
#endif
    return L"ARX";
}

const AcString getPyRxBuldVersion()
{
    constexpr TCHAR MAJOR1 = '2';
    constexpr TCHAR MINOR1 = '1';
    constexpr TCHAR REVISION1 = '0', REVISION2 = '0', REVISION3 = '9';

    constexpr unsigned int compileYear = (__DATE__[7] - '0') * 1000 + (__DATE__[8] - '0') * 100 + (__DATE__[9] - '0') * 10 + (__DATE__[10] - '0');
    constexpr unsigned int compileMonth = (__DATE__[0] == 'J') ? ((__DATE__[1] == 'a') ? 1 : ((__DATE__[2] == 'n') ? 6 : 7))    // Jan, Jun or Jul
        : (__DATE__[0] == 'F') ? 2                                                              // Feb
        : (__DATE__[0] == 'M') ? ((__DATE__[2] == 'r') ? 3 : 5)                                 // Mar or May
        : (__DATE__[0] == 'A') ? ((__DATE__[2] == 'p') ? 4 : 8)                                 // Apr or Aug
        : (__DATE__[0] == 'S') ? 9                                                              // Sep
        : (__DATE__[0] == 'O') ? 10                                                             // Oct
        : (__DATE__[0] == 'N') ? 11                                                             // Nov
        : (__DATE__[0] == 'D') ? 12                                                             // Dec
        : 0;
    constexpr unsigned int compileDay = (__DATE__[4] == ' ') ? (__DATE__[5] - '0') : (__DATE__[4] - '0') * 10 + (__DATE__[5] - '0');

    constexpr TCHAR IsoDate[] =
    {
       MAJOR1, '.' , MINOR1 , '.', REVISION1, REVISION2, REVISION3,
       '.', compileYear / 1000 + '0', (compileYear % 1000) / 100 + '0', (compileYear % 100) / 10 + '0', compileYear % 10 + '0',
       compileMonth / 10 + '0', compileMonth % 10 + '0',
       compileDay / 10 + '0', compileDay % 10 + '0', 0
    };
    return AcString(IsoDate);
}