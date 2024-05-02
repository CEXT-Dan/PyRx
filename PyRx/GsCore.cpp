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
#if !defined (_BRXTARGET240)
        acgsGetGsManager()->destroyView(ptr);
#endif
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

static int cvport()
{
    struct resbuf rb;
    acedGetVar(_T("CVPORT"), &rb);
    return rb.resval.rint;
}

#ifdef PYRXDEBUG
static std::wstring AcGeMatrix3dToString(const AcGeMatrix3d& x)
{
    return std::format(L"(({0},{1},{2},{3}),({4},{5},{6},{7}),({8},{9},{10},{11}),({12},{13},{14},{15}))",
        x.entry[0][0], x.entry[0][1], x.entry[0][2], x.entry[0][3],
        x.entry[1][0], x.entry[1][1], x.entry[1][2], x.entry[1][3],
        x.entry[2][0], x.entry[2][1], x.entry[2][2], x.entry[2][3],
        x.entry[3][0], x.entry[3][1], x.entry[3][2], x.entry[3][3]);
}
#endif

PyObject* GsCore::getBlockImage(const PyDbObjectId& blkid, int width, int height)
{
#if defined(_ZRXTARGET)
    PyThrowBadEs(Acad::eNotImplementedYet);
    return nullptr;
#endif
#if defined(_GRXTARGET)
    PyThrowBadEs(Acad::eNotImplementedYet);
    return nullptr;
#endif

    PyAutoLockGIL lock;
    AcGsManager* gsManager = acgsGetGsManager();

    AcGsKernelDescriptor descriptor;
    descriptor.addRequirement(AcGsKernelDescriptor::k3DDrawing);

    AcGsGraphicsKernel* pGraphicsKernel = AcGsManager::acquireGraphicsKernel(descriptor);
    if (pGraphicsKernel == nullptr)
        return nullptr;
    //?
    AcGsDevicePtr pOffDevice(gsManager->createAutoCADOffScreenDevice(*pGraphicsKernel));
    pOffDevice->onSize(width, height);

    AcGsModelPtr pModel(gsManager->createAutoCADModel(*pGraphicsKernel));
    AcGsViewPtr pView(gsManager->createView(pOffDevice.get()));
    if (!pOffDevice->add(pView.get()))
        return nullptr;

    bool flag = acgsGetViewParameters(cvport(), pView.get());

#ifdef PYRXDEBUG
    auto uv = pView->upVector();
    acutPrintf(_T("\n(%f,%f,%f)"), uv.x, uv.y, uv.z);
    auto tg = pView->target();
    acutPrintf(_T("\n(%f,%f,%f)"), tg.x, tg.y, tg.z);
    acutPrintf(_T("\n%ls"),AcGeMatrix3dToString(pView->viewingMatrix()).c_str());
#endif

    AcDbBlockTableRecordPointer pBlock(blkid.m_id);
    if (!pView->add(pBlock, pModel.get()))
        return nullptr;

    AcDbExtents ex;
    ex.addBlockExt(pBlock);
    pView->zoomExtents(ex.minPoint(), ex.maxPoint());

    pOffDevice->update();
    pView->update();

    Atil::RgbModel rgbModel(32);
    Atil::ImagePixel initialColor(rgbModel.pixelType());
    Atil::Image image(Atil::Size(width, height), &rgbModel, initialColor);

#ifdef PYRXDEBUG//TODO: Add this
    AcGsColor bkclr;
    bkclr.m_blue = 128;
    bkclr.m_green = 128;
    bkclr.m_red = 128;
    pOffDevice->setBackgroundColor(bkclr);
#endif

#if defined(_ARXTARGET)
    auto v = pView->upVector();
    pView->setView(pView->position(), pView->target(), v.negate(), pView->fieldWidth(), pView->fieldHeight());
#endif

    pView->getSnapShot(&image, AcGsDCPoint(0, 0));
    if (!image.isValid())
        return nullptr;

    Atil::Offset upperLeft(0, 0);
    Atil::Size wholeImage = image.size();
    Atil::ImageContext* imgContext = image.createContext(Atil::ImageContext::kWrite, wholeImage, upperLeft);
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

#if defined(_ARXTARGET)
     *pWxImage = pWxImage->Mirror();
#endif // _ARXTARGET

    pView->eraseAll();

    PyObject* _wxobj = wxPyConstructObject(pWxImage, wxT("wxImage"));
    if (_wxobj == nullptr)
        throw PyNullObject();
    return _wxobj;
}
