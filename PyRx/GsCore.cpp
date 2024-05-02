#include "stdafx.h"
#include "stdafx.h"
#include "GsCore.h"
#include "PyGsView.h"
#include "PyDbObjectId.h"
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

struct AcGsViewDeleter
{
    explicit AcGsViewDeleter(AcGsGraphicsKernel* pGraphicsKernel)
        :m_pGraphicsKernel(pGraphicsKernel)
    {
    }
    void operator()(AcGsView* ptr)
    {
        m_pGraphicsKernel->deleteView(ptr);
    }
    AcGsGraphicsKernel* m_pGraphicsKernel = nullptr;
};
using AcGsViewPtr = std::unique_ptr <AcGsView, AcGsViewDeleter>;


struct AcGsModelDeleter
{
    AcGsModelDeleter(AcGsGraphicsKernel* pGraphicsKernel)
        :m_pGraphicsKernel(pGraphicsKernel)
    {
    }
    void operator()(AcGsModel* ptr)
    {
        m_pGraphicsKernel->deleteModel(ptr);
    }
    AcGsGraphicsKernel* m_pGraphicsKernel = nullptr;
};
using AcGsModelPtr = std::unique_ptr <AcGsModel, AcGsModelDeleter>;


Atil::DataModel* colorSpace(char*& pRGBData, int colorDepth, int paletteSize)
{
    Atil::DataModel* pDm = NULL;
    if (colorDepth == 8)
    {
        Atil::RgbColor space[256];
        Atil::RgbPaletteModel* pPM = new Atil::RgbPaletteModel();
        pDm = pPM;
        char* palette = pRGBData;
        pRGBData += paletteSize;
        for (int i = 0; i < paletteSize; i += 4)
            space[i / 4] = Atil::RgbColor(palette[i + 2], palette[i + 1], palette[i], 255);
        pPM->setEntries(0, 256, (Atil::RgbColor*)&space);
    }
    else
    {
        pDm = new Atil::RgbModel(32);
    }
    return pDm;
}

Atil::Image* constructAtilImg(char* pRGBData, unsigned long bufferSize, unsigned long rowBytes, unsigned long xSize, unsigned long ySize, int colorDepth, int paletteSize)
{
    if ((8 != colorDepth) && (32 != colorDepth))
        return NULL;

    if (paletteSize)
    {
        if ((paletteSize < 0) || (paletteSize > 255))
            return NULL;
    }

    if ((xSize <= 0) || (ySize <= 0))
        return NULL;

    Atil::Image* pImg = NULL;
    Atil::Size size(xSize, ySize);

    // construct the Atil::Image object
    if (pRGBData)
    {
        // Check the buffer for size and definition
        if (bufferSize)
        {
            if (!rowBytes)
                return NULL;
            // did they allocate enough?
            if (rowBytes * ySize > bufferSize)
                return NULL;
        }
        else
        {
            return NULL;
        }
        std::unique_ptr<Atil::DataModel> pM(colorSpace(pRGBData, colorDepth, paletteSize));
        if (NULL == pM)
        {
            return NULL;
        }
        try
        {
            // BEWARE: pRGBData may be moved in colorSpace
            pImg = new Atil::Image(pRGBData, bufferSize, rowBytes, size, pM.get());

        }
        catch (...)
        {
            pImg = NULL;
            return NULL;
        }
    }
    else 
    {

        Atil::RgbModel rgbM(32);
        Atil::RgbGrayModel gM;
        Atil::ImagePixel initialColor(colorDepth == 32 ? Atil::DataModelAttributes::kRgba : Atil::DataModelAttributes::kGray);
        initialColor.setToZero();
        try
        {
            pImg = new Atil::Image(size, colorDepth == 32 ? &rgbM : &gM, initialColor);
        }
        catch (...)
        {
            pImg = NULL;
            return NULL;
        }
    }
    return pImg;

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
    AcGsKernelDescriptor descriptor;
    descriptor.addRequirement(AcGsKernelDescriptor::k3DDrawing);
    AcGsGraphicsKernel* pGraphicsKernel = AcGsManager::acquireGraphicsKernel(descriptor);
    if (pGraphicsKernel == nullptr)
        return nullptr;

    AcGsDevice* pOffDevice = pGraphicsKernel->createOffScreenDevice();
    AcGsModelPtr pModel (acgsGetGsManager()->createAutoCADModel(*pGraphicsKernel), AcGsModelDeleter{ pGraphicsKernel });
    AcGsViewPtr pView(acgsGetGsManager()->createView(pOffDevice), AcGsViewDeleter{ pGraphicsKernel });
    pOffDevice->add(pView.get());

    AcDbBlockTableRecordPointer pBlock(blkid.m_id);
    AcDbBlockReference ref(AcGePoint3d::kOrigin, blkid.m_id);
    pView->add(pBlock, pModel.get());
    pView->zoomExtents(AcGePoint3d(0, 0, 0), AcGePoint3d(1000, 1000, 0));
    pView->update();

    Atil::Size size(width, height);
    int nBytesPerRow = Atil::DataModel::bytesPerRow(width, Atil::DataModelAttributes::k32);
    unsigned long nBufferSize = height * nBytesPerRow;
    std::unique_ptr<char[]>apCharBuffer(new char[nBufferSize]);
    char* pSnapshotData = apCharBuffer.get();
    std::unique_ptr <Atil::Image> pImage (constructAtilImg(pSnapshotData, nBufferSize, nBytesPerRow, width, height, 32, 0));
    pOffDevice->getSnapShot(pImage.get(), AcGsDCPoint(0, 0));
    if (!pImage->isValid())
        return nullptr;

    Atil::Offset upperLeft(0, 0);
    Atil::Size wholeImage = pImage->size();
    Atil::ImageContext* imgContext = pImage->createContext(Atil::ImageContext::kRead, wholeImage, upperLeft);
    Atil::DataModelAttributes::PixelType pixelType = imgContext->getPixelType();
    if (pixelType != Atil::DataModelAttributes::kRgba)
        return nullptr;


    wxImage *pWxImage = new wxImage(wxSize(wholeImage.width, wholeImage.height));

    for (int x = 0; x < wholeImage.width; ++x)
    {
        for (int y = 0; y < wholeImage.height; ++y)
        {
            Atil::RgbColor p(imgContext->get32(x, y));
            pWxImage->SetRGB(x, y, p.rgba.red, p.rgba.green, p.rgba.blue);
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
