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
//----- DocData.h : include file for document specific data. An instance of this
//----- class is automatically created and managed by the AsdkDataManager class.
//----- See the AsdkDmgr.h / DocData.cpp for more datails
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------------------
//---- AcGiImageBGRA32Package storage for acedAddSupplementalCursorImage
#if defined(_ARXTARGET)
class wxImage;
class AcGiImageBGRA32Package
{
public:
    AcGiImageBGRA32Package(const wxImage& wximage, Adesk::UInt8 alpha);
    void create(const wxImage& wximage, Adesk::UInt8 alpha);
public:
    AcGiImageBGRA32 _acImage;
    std::vector<AcGiPixelBGRA32> _pixelData;
};
#endif

//-----------------------------------------------------------------------------
//----- Here you can store the document / database related data.
class CDocData 
{
public:
    CDocData();
    CDocData(const CDocData& data);
    ~CDocData();

#if defined(_ARXTARGET)
    AcGiImageBGRA32* createCursorImage(const wxImage& wximage, Adesk::UInt8 alpha);
    AcGiImageBGRA32* getCursorImage();
    void             clearCursorImage();
#endif

public:
    boost::python::object m_userdata;
#if defined(_ARXTARGET)
    std::unique_ptr<AcGiImageBGRA32Package> m_pAcImage;
#endif
};
