#include "stdafx.h"
#include "stdafx.h"
#include "GsCore.h"
#include "PyGsView.h"
#include "PyDbObjectId.h"
#include "AcGsManager.h"
//#include "format_codecs/PngFormatCodec.h"


//ZWCAD 'register' is no longer a supported storage class
#pragma warning( disable: 5033 )
#include "Image.h"
#include "RgbModel.h"
#include "RgbGrayModel.h"
#include "RgbPaletteModel.h"
#include "RgbPaletteModel.h"
#include "codec_properties/FormatCodecPropertyInterface.h"
#include "format_codecs/BmpFormatCodec.h"
#include "RowProviderInterface.h"
#include "FileWriteDescriptor.h"
#include "DataBuffer.h"
#pragma warning( pop )

using namespace boost::python;

//https://adndevblog.typepad.com/autocad/2013/01/capturing-a-screen-shot-using-objectarx.html

struct AcGsDeviceDeleter
{
    void operator()(AcGsDevice* ptr)
    {
        acgsGetGsManager()->destroyAutoCADDevice(ptr);
    }
};
using AcGsDevicePtr = std::unique_ptr <AcGsDevice, AcGsDeviceDeleter>;

struct AcGsViewDeleter
{
    void operator()(AcGsView* ptr)
    {
        //acgsGetGsManager()->destroyAutoCADView(ptr);
    }
};
using AcGsViewPtr = std::unique_ptr <AcGsView, AcGsViewDeleter>;

struct AcGsModelDeleter
{
    void operator()(AcGsModel* ptr)
    {
        acgsGetGsManager()->destroyAutoCADModel(ptr);
    }
};
using AcGsModelPtr = std::unique_ptr <AcGsModel, AcGsModelDeleter>;


Atil::Image* constructAtilImg(char* pRGBData, unsigned long bufferSize, unsigned long rowBytes, unsigned long xSize, unsigned long ySize, int colorDepth, int paletteSize)
{
    if ((8 != colorDepth) && (32 != colorDepth))
        return nullptr;
    if (paletteSize)
    {
        if ((paletteSize < 0) || (paletteSize > 255))
            return nullptr;
    }
    if ((xSize <= 0) || (ySize <= 0))
        return nullptr;
    // construct the Atil::Image object
    if (!pRGBData)
        return nullptr;

    // Check the buffer for size and definition
    if (!bufferSize)
        return nullptr;

    if (!rowBytes)
        return nullptr;
    // did they allocate enough?
    if (rowBytes * ySize > bufferSize)
        return nullptr;
    try
    {
        Atil::RgbModel rgbM(32);
        Atil::Size size(xSize, ySize);
        Atil::Image* pImg = new Atil::Image(pRGBData, bufferSize, rowBytes, size, &rgbM);
        return pImg;
    }
    catch (...)
    {
        acutPrintf(_T("Exception in %ls: ")__FUNCTIONW__);
    }
    return nullptr;

}

void makeGsCoreWrapper()
{
    PyDocString DS("Core");
    class_<GsCore>("Core")
        .def("getCurrentAcGsView", &GsCore::getCurrentAcGsView, DS.SARGS({ "vpNum : int" })).staticmethod("getCurrentAcGsView")
        .def("getCurrent3DAcGsView", &GsCore::getCurrent3DAcGsView, DS.SARGS({ "vpNum : int" })).staticmethod("getCurrent3DAcGsView")
        .def("getViewParameters", &GsCore::getViewParameters, DS.SARGS({ "vpNum : int", "view : PyGs.View" })).staticmethod("getViewParameters")
        .def("setViewParameters", &GsCore::setViewParameters1)
        .def("setViewParameters", &GsCore::setViewParameters2, DS.SARGS({ "vpNum : int", "view : PyGs.View", "bRegenRequired: bool","bRescaleRequired: bool","bSyncRequired: bool=False" })).staticmethod("setViewParameters")
        .def("getBlockImage", &GsCore::getBlockImage, DS.SARGS({ "blkid: PyDb.ObjectId" , "sx: int", "sy: int" })).staticmethod("getBlockImage")
        ;
}

PyGsView GsCore::getCurrentAcGsView(int vpNum)
{
    return PyGsView(acgsGetCurrentAcGsView(vpNum), false);
}

PyGsView GsCore::getCurrent3DAcGsView(int vpNum)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyGsView(acgsGetCurrent3dAcGsView(vpNum), false);
#endif
}

bool GsCore::getViewParameters(int vpNum, PyGsView& view)
{
    return acgsGetViewParameters(vpNum, view.impObj());
}

bool GsCore::setViewParameters1(int viewportNumber, const PyGsView& obj, bool bRegenRequired, bool bRescaleRequired)
{
    return acgsSetViewParameters(viewportNumber, obj.impObj(), bRegenRequired, bRescaleRequired);
}

bool GsCore::setViewParameters2(int viewportNumber, const PyGsView& obj, bool bRegenRequired, bool bRescaleRequired, bool bSyncRequired)
{
    return acgsSetViewParameters(viewportNumber, obj.impObj(), bRegenRequired, bRescaleRequired, bSyncRequired);
}

PyObject* GsCore::getBlockImage(const PyDbObjectId& blkid, int width, int height)
{
#ifdef PYRXDEBUG

    PyAutoLockGIL lock;

    AcGsManager* gsManager = acgsGetGsManager();

    AcGsKernelDescriptor descriptor;
    descriptor.addRequirement(AcGsKernelDescriptor::k3DRapidRTRendering);

    AcGsGraphicsKernel* pGraphicsKernel = AcGsManager::acquireGraphicsKernel(descriptor);
    if (pGraphicsKernel == nullptr)
        return nullptr;

    //?
    AcGsDevicePtr pOffDevice(gsManager->createAutoCADOffScreenDevice(*pGraphicsKernel));
    AcGsModelPtr pModel(gsManager->createAutoCADModel(*pGraphicsKernel));
    AcGsViewPtr pView(gsManager->createView(pOffDevice.get()));

    AcDbEntityUPtr pRef(new AcDbBlockReference(AcGePoint3d(0, 0, 0), blkid.m_id));
    if (!pOffDevice->add(pView.get()))
        return nullptr;
    if (!pView->add(pRef.get(), pModel.get()))
        return nullptr;

    //gray, so getSnapShot should be gray
    AcGsColor bkclr;
    bkclr.m_red = 128;
    bkclr.m_green = 128;
    bkclr.m_blue = 128;
    pOffDevice->setBackgroundColor(bkclr);

    pView->zoomWindow(AcGePoint2d(0, 0), AcGePoint2d(width, height));

    //Atil::Size size(width, height);
    //int nBytesPerRow = Atil::DataModel::bytesPerRow(width, Atil::DataModelAttributes::k32);
    //unsigned long nBufferSize = height * nBytesPerRow;

    //std::vector<char> apCharBuffer(nBufferSize);
    //std::unique_ptr <Atil::Image> pImage(constructAtilImg(apCharBuffer.data(), nBufferSize, nBytesPerRow, width, height, 32, 0));

    Atil::RgbModel rgbModel(32);
    Atil::ImagePixel initialColor(rgbModel.pixelType());
    std::unique_ptr <Atil::Image> pImage(new Atil::Image (Atil::Size(width, height), &rgbModel, initialColor));

    //
    pView->getSnapShot(pImage.get(), AcGsDCPoint(0, 0));
    if (!pImage->isValid())
        return nullptr;

    Atil::Offset upperLeft(0, 0);
    Atil::Size wholeImage = pImage->size();
    Atil::ImageContext* imgContext = pImage->createContext(Atil::ImageContext::kRead, wholeImage, upperLeft);
    Atil::DataModelAttributes::PixelType pixelType = imgContext->getPixelType();
    if (pixelType != Atil::DataModelAttributes::kRgba)
        return nullptr;

    //I know, I'll work on this later
    wxImage* pWxImage = new wxImage(wxSize(wholeImage.width, wholeImage.height));
    for (int x = 0; x < wholeImage.width; ++x)
    {
        for (int y = 0; y < wholeImage.height; ++y)
        {
            Atil::RgbColor pix(imgContext->get32(x, y));
            const auto& rgba = pix.rgba;
            pWxImage->SetRGB(x, y, rgba.red, rgba.green, rgba.blue);
        }
    }
    if (!pWxImage->IsOk())
        return nullptr;

    pView->eraseAll();
    pOffDevice->eraseAll();

    PyObject* _wxobj = wxPyConstructObject(pWxImage, wxT("wxImage"));
    if (_wxobj == nullptr)
        throw PyNullObject();
    return _wxobj;
#else
    PyThrowBadEs(Acad::eNotImplementedYet);
    return nullptr;
#endif
}
