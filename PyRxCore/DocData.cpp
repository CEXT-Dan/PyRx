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
//----- DocData.cpp : Implementation file
//-----------------------------------------------------------------------------
#include "StdAfx.h"

//-----------------------------------------------------------------------------------------
//---- AcGiImageBGRA32Package storage for acedAddSupplementalCursorImage
// and PyGiGeometry::image
AcGiImageBGRA32Package::AcGiImageBGRA32Package(const wxImage& wximage, Adesk::UInt8 alpha)
{
    create(wximage, alpha);
}

void AcGiImageBGRA32Package::create(const wxImage& wximage, Adesk::UInt8 alpha)
{
    //0.000018 for a 32x32
    _pixelData.reserve(static_cast<size_t>(wximage.GetWidth()) * wximage.GetHeight());
    if (wximage.HasAlpha())
    {
        for (Adesk::UInt32 y = 0; y < wximage.GetHeight(); y++)
        {
            for (Adesk::UInt32 x = 0; x < wximage.GetWidth(); x++)
                _pixelData.emplace_back(AcGiPixelBGRA32{ wximage.GetBlue(x,y), wximage.GetGreen(x,y), wximage.GetRed(x,y), wximage.GetAlpha(x,y) });
        }
    }
    else
    {
        for (Adesk::UInt32 y = 0; y < wximage.GetHeight(); y++)
        {
            for (Adesk::UInt32 x = 0; x < wximage.GetWidth(); x++)
                _pixelData.emplace_back(AcGiPixelBGRA32{ wximage.GetBlue(x,y), wximage.GetGreen(x,y), wximage.GetRed(x,y), alpha });
        }
    }
    _acImage.setImage(wximage.GetWidth(), wximage.GetHeight(), _pixelData.data());
}

//-----------------------------------------------------------------------------
//----- The one and only document manager object. You can use the DocVars object to retrieve
//----- document specific data throughout your application
AcApDataManager<CDocData> DocVars;

//-----------------------------------------------------------------------------
//----- Implementation of the document data class.
CDocData::CDocData()
{
}

//-----------------------------------------------------------------------------
CDocData::CDocData(const CDocData& data)
{
}

//-----------------------------------------------------------------------------
CDocData::~CDocData()
{
    PyAutoLockGIL lock;
    m_userdata = boost::python::object();

#if defined(_ARXTARGET)
    if (m_pAcImage.get())
        clearCursorImage();
#endif
}

#if defined(_ARXTARGET)
AcGiImageBGRA32* CDocData::createCursorImage(const wxImage& wximage, Adesk::UInt8 alpha)
{
    m_pAcImage.reset(new AcGiImageBGRA32Package{ wximage, alpha });
    return getCursorImage();
}
#endif

#if defined(_ARXTARGET)
AcGiImageBGRA32* CDocData::getCursorImage()
{
    if (m_pAcImage.get())
        return &m_pAcImage->_acImage;
    return nullptr;
}
#endif

#if defined(_ARXTARGET)
void CDocData::clearCursorImage()
{
    m_pAcImage.reset();
}
#endif
