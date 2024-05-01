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
#pragma warning( pop )

using namespace boost::python;

//https://adndevblog.typepad.com/autocad/2013/01/capturing-a-screen-shot-using-objectarx.html

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
    AcGsKernelDescriptor descriptor;
    descriptor.addRequirement(AcGsKernelDescriptor::k3DDrawing);
    AcGsGraphicsKernel* pGraphicsKernel = AcGsManager::acquireGraphicsKernel(descriptor);
    if (pGraphicsKernel == nullptr)
        return nullptr;

    AcGsDevice* pOffDevice = pGraphicsKernel->createOffScreenDevice();
    AcGsModel* pModel = acgsGetGsManager()->createAutoCADModel(*pGraphicsKernel);

    AcGsView* view = acgsGetGsManager()->createView(pOffDevice);
    pOffDevice->add(view);

    AcDbBlockTableRecordPointer pBlock(blkid.m_id);
    view->add(pBlock, pModel);

    Atil::Size size(width, height);
    int nBytesPerRow = Atil::DataModel::bytesPerRow(width, Atil::DataModelAttributes::k32);
    unsigned long nBufferSize = height * nBytesPerRow;
    std::unique_ptr<char[]>apCharBuffer(new char[nBufferSize]);
    char* pSnapshotData = apCharBuffer.get();
    std::unique_ptr <Atil::Image> pImage (constructAtilImg(pSnapshotData, nBufferSize, nBytesPerRow, width, height, 32, 0));
    view->getSnapShot(pImage.get(), AcGsDCPoint(0, 0));
    std::unique_ptr <Atil::ImageFormatCodec> pCodec (new BmpFormatCodec());

    Atil::RowProviderInterface* pPipe = pImage->read(pImage->size(), Atil::Offset(0, 0));

    Atil::FileWriteDescriptor* pFWD = new Atil::FileWriteDescriptor(pCodec.get());


    wxImage wximage;
    wximage.IsOk();

    view->eraseAll();
    pOffDevice->eraseAll();

    pGraphicsKernel->deleteView(view);
    pGraphicsKernel->deleteModel(pModel);

    PyObject* _wxobj = wxPyConstructObject(&wximage, wxT("wxImage"));
    if (_wxobj == nullptr)
        throw PyNullObject();
    return _wxobj;

#else
    PyThrowBadEs(Acad::eNotImplementedYet);
    return nullptr;
#endif
}
