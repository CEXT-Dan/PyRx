#include "stdafx.h"
#include "GsCore.h"
#include "PyGsView.h"
#include "PyDbObjectId.h"
#include "AcGsManager.h"
#include <fstream>


using namespace boost::python;

//https://adndevblog.typepad.com/autocad/2013/01/capturing-a-screen-shot-using-objectarx.html

//------------------------------------------------------------------------------------
//GsCore Helpers
static void setBackgroundColorFromPy(AcGsDevice* pDevice, const boost::python::object& rgb)
{
    if (pDevice != nullptr && !rgb.is_none())
    {
        auto _rgb = PyListToInt32Array(rgb);
        if (_rgb.length() == 3)
        {
            AcGsColor bkclr{};
            bkclr.m_red = _rgb[0];
            bkclr.m_green = _rgb[1];
            bkclr.m_blue = _rgb[2];
            pDevice->setBackgroundColor(bkclr);
        }
    }
}

static AcDbExtents calcBlockExtents(AcDbBlockTableRecord& rec)
{
    AcDbExtents ex;
    auto [es, iter] = makeBlockTableRecordIterator(rec);
    if (es != eOk)
    {
        ex.addBlockExt(&rec);
        return ex;
    }
    AcDbObjectId id;
    for (iter->start(); !iter->done(); iter->step())
    {
        if (iter->getEntityId(id) == eOk)
        {
            AcDbExtents subex;
            AcDbEntityPointer pEnt(id);
            if (pEnt->visibility() == AcDb::kVisible)
            {
                if (pEnt->getGeomExtents(subex) == eOk)
                    ex.addExt(subex);
            }
        }
    }
    return ex;
}

void AcGsGraphicsKernelDeleter::operator()(AcGsGraphicsKernel* ptr)
{
    if (ptr == nullptr)
        return;
    acgsGetGsManager()->releaseGraphicsKernel(ptr);
}

void AcGsDeviceDeleter::operator()(AcGsDevice* ptr)
{
    if (ptr == nullptr)
        return;
    acgsGetGsManager()->destroyAutoCADDevice(ptr);
}

void AcGsViewDeleter::operator()(AcGsView* ptr)
{
    if (ptr == nullptr)
        return;
    acgsGetGsManager()->destroyAutoCADView(ptr);
}

void AcGsModelDeleter::operator()(AcGsModel* ptr)
{
    if (ptr == nullptr)
        return;
    acgsGetGsManager()->destroyAutoCADModel(ptr);
}

BlockImageRenderer::BlockImageRenderer(int width, int height, const boost::python::object& rgb)
    : m_width(width)
    , m_height(height)
    , m_isReady(false)
    , m_rgbModel(32)
    , m_initialColor(m_rgbModel.pixelType())
{
    AcGsManager* gsManager = acgsGetGsManager();
    AcGsKernelDescriptor descriptor;
    descriptor.addRequirement(AcGsKernelDescriptor::k3DDrawing);
    m_pGraphicsKernel.reset(AcGsManager::acquireGraphicsKernel(descriptor));
    if (m_pGraphicsKernel == nullptr)
        return;

    m_pOffDevice.reset(gsManager->createAutoCADOffScreenDevice(*m_pGraphicsKernel));
    if (m_pOffDevice == nullptr)
        return;

#if defined(_ZRXTARGET) || defined(_GRXTARGET)//TODO: test this in acad, bcad
    m_pView.reset(m_pGraphicsKernel->createView());
    if (m_pView == nullptr)
        PyThrowBadEs(eNullPtr);
#else
    m_pView.reset(gsManager->createView(m_pOffDevice.get()));
    if (m_pView == nullptr)
        PyThrowBadEs(eNullPtr);
#endif

    m_pModel.reset(gsManager->createAutoCADModel(*m_pGraphicsKernel));
    if (m_pModel == nullptr)
        return;

    m_pOffDevice->onSize(m_width, m_height);
    if (!m_pOffDevice->add(m_pView.get()))
        return;

    m_pView->setVisualStyle(acdbGetViewportVisualStyle());
    setBackgroundColorFromPy(m_pOffDevice.get(), rgb);
#if !defined(_BRXTARGET)
    m_pView->setView(m_pView->position(), m_pView->target(), m_pView->upVector().negate(), m_width, m_height);
#else
    m_pView->setView(m_pView->position(), m_pView->target(), m_pView->upVector(), m_width, m_height);
#endif// _BRXTARGET
    setBackgroundColorFromPy(m_pOffDevice.get(), rgb);
    m_isReady = true;
}

bool BlockImageRenderer::isValid() const
{
    return m_isReady;
}

wxImage BlockImageRenderer::render(AcDbBlockTableRecord* pBlock, double zoomFactor)
{
    if (pBlock == nullptr || !isValid())
        return wxImage{};

    if (!m_pView->add(pBlock, m_pModel.get()))
        return wxImage{};

    AcDbExtents ex = calcBlockExtents(*pBlock);
    m_pView->zoomExtents(ex.minPoint(), ex.maxPoint());
    m_pView->zoom(zoomFactor);

    m_pOffDevice->update();

    Atil::Image image(Atil::Size(m_width, m_height), &m_rgbModel, m_initialColor);
    m_pView->getSnapShot(&image, AcGsDCPoint(0, 0));

    wxImage wximage;
    if (image.isValid())
    {
        Atil::Size imageSize = image.size();
        std::unique_ptr<Atil::ImageContext> imgContext(image.createContext(Atil::ImageContext::kRead, imageSize, Atil::Offset(0, 0)));
        if (imgContext && imgContext->getPixelType() == Atil::DataModelAttributes::kRgba)
        {
            wximage.Create(wxSize(imageSize.width, imageSize.height), false);
            unsigned char* rgbData = wximage.GetData();

            wximage.InitAlpha();
            unsigned char* alphaData = wximage.GetAlpha();
            std::vector<Atil::RgbColor> rowBuffer(imageSize.width);

            for (Atil::Int32 y = 0; y < imageSize.height; ++y)
            {
                imgContext->getRow(y, 0, imageSize.width, rowBuffer.data());

                for (Atil::Int32 x = 0; x < imageSize.width; ++x)
                {
#if defined(_BRXTARGET)
                    const Atil::RgbColor& pix = rowBuffer[x];
#else
                    const Atil::RgbColor& pix = rowBuffer[imageSize.width - 1 - x];
#endif

                    * rgbData++ = pix.rgba.red;
                    *rgbData++ = pix.rgba.green;
                    *rgbData++ = pix.rgba.blue;

                    if (alphaData)
                    {
                        *alphaData++ = pix.rgba.alpha;
                    }
                }
            }
        }
    }
    m_pView->erase(pBlock);
    if (!wximage.IsOk())
    {
        PyThrowBadEs(eInvalidInput);
    }
    return wximage;
}


//------------------------------------------------------------------------------------
//GsCore
void makeGsCoreWrapper()
{
    PyDocString DS("Core");
    class_<GsCore>("Core")
        .def("getCurrentAcGsView", &GsCore::getCurrentAcGsView, DS.SARGS({ "vpNum : int" })).staticmethod("getCurrentAcGsView")
        .def("getCurrent3DAcGsView", &GsCore::getCurrent3DAcGsView, DS.SARGS({ "vpNum : int" })).staticmethod("getCurrent3DAcGsView")
        .def("getViewParameters", &GsCore::getViewParameters, DS.SARGS({ "vpNum : int", "view : PyGs.View" })).staticmethod("getViewParameters")

        .def("setViewParameters", &GsCore::setViewParameters1)
        .def("setViewParameters", &GsCore::setViewParameters2,
            DS.SARGS({ "vpNum : int", "view : PyGs.View", "bRegen: bool","bRescale: bool","bSync: bool=False" })).staticmethod("setViewParameters")

        .def("getBlockImage", &GsCore::getBlockImage,
            DS.SARGS({ "blkid: PyDb.ObjectId" , "sx: int", "sy: int", "zoomFactor: float", "bkrgb: list[int] = ..." }), arg("bkrgb") = boost::python::object()).staticmethod("getBlockImage")

        .def("getBlockImages", &GsCore::getBlockImages,
            DS.SARGS({ "blkids: list[PyDb.ObjectId]" , "sx: int", "sy: int", "zoomFactor: float", "bkrgb: list[int] = ..." }), arg("bkrgb") = boost::python::object()).staticmethod("getBlockImages")

        .def("displayImage", &GsCore::displayImage, DS.SARGS({ "vpNum : int", "originLeft : int",  "originBottom : int" , "img : wx.Image" })).staticmethod("displayImage")

        .def("slideToWxImage", &GsCore::slideToWxImage, DS.SARGS({ "path : str", "width : int",  "height : int", "rgb:list" })).staticmethod("slideToWxImage")
        ;
}

PyGsView GsCore::getCurrentAcGsView(int vpNum)
{
    return PyGsView(acgsGetCurrentAcGsView(vpNum), false);
}

PyGsView GsCore::getCurrent3DAcGsView(int vpNum)
{
#if defined(_BRXTARGET270)
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

PyObject* GsCore::getBlockImage(const PyDbObjectId& blkid, int width, int height, double zf, boost::python::object& pyrgb)
{
#if defined(_GRXTARGET270)
    throw PyNotimplementedByHost();
    return nullptr;
#endif
    AcAxDocLock lock;
    PyAutoLockGIL pylock;
    BlockImageRenderer renderer(width, height, pyrgb);
    if (!renderer.isValid())
        throw PyErrorStatusException(eInvalidInput);
    AcDbBlockTableRecordPointer pBlock(blkid.m_id);
    if (pBlock.openStatus() != eOk)
        throw PyErrorStatusException(pBlock.openStatus());
    const auto& image = renderer.render(pBlock, zf);
    return wxPyConstructObject((void*)new wxImage(image), wxT("wxImage"), true);
}

boost::python::list GsCore::getBlockImages(const boost::python::list& blkids, int x, int y, double zf, const boost::python::object& rgb)
{
#if defined(_GRXTARGET270)
    throw PyNotimplementedByHost();
#endif
    AcAxDocLock lock;
    PyAutoLockGIL pylock;
    auto ids = PyListToObjectIdArray(blkids);
    BlockImageRenderer renderer(x, y, rgb);
    if (!renderer.isValid())
        throw PyErrorStatusException(eInvalidInput);
    boost::python::list images;
    for (auto& id : ids)
    {
        AcDbBlockTableRecordPointer pBlock(id);
        if (pBlock.openStatus() != eOk)
            continue;
        const auto& image = renderer.render(pBlock, zf);
        images.append(boost::python::object(boost::python::handle<>(wxPyConstructObject((void*)new wxImage(image), wxT("wxImage"), true))));
    }
    return images;
}

bool GsCore::displayImage(int viewportNumber, Adesk::Int32 originLeft, Adesk::Int32 originBottom, const boost::python::object& image)
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    wxImage* img = nullptr;// we are NOT the owner!
    if (!wxPyConvertWrappedPtr(image.ptr(), (void**)&img, wxT("wxImage")))
        return false;
    if (!img->IsOk())
        return false;

    int imageWidth = img->GetWidth();
    int imageHeight = img->GetHeight();
    bool hasAlpha = img->HasAlpha();
    int numPixels = imageWidth * imageHeight;

    // Allocate contiguous array of 32-bit longwords (Adesk::Int32)
    std::vector<Adesk::Int32> argbBuffer(numPixels);

    const unsigned char* rgbData = img->GetData();
    const unsigned char* alphaData = hasAlpha ? img->GetAlpha() : nullptr;

#if defined(_BRXTARGET)
    // Flip vertically for BricsCAD
    for (int y = 0; y < imageHeight; ++y)
    {
        // Read from the bottom up in the source image
        int srcY = imageHeight - 1 - y;

        for (int x = 0; x < imageWidth; ++x)
        {
            int destIndex = y * imageWidth + x;
            int srcIndex = srcY * imageWidth + x;

            unsigned char r = rgbData[srcIndex * 3 + 0];
            unsigned char g = rgbData[srcIndex * 3 + 1];
            unsigned char b = rgbData[srcIndex * 3 + 2];
            unsigned char a = 0xFF;

            if (hasAlpha && alphaData) {
                a = alphaData[srcIndex];
            }

            argbBuffer[destIndex] = (static_cast<Adesk::Int32>(a) << 24) |
                (static_cast<Adesk::Int32>(r) << 16) |
                (static_cast<Adesk::Int32>(g) << 8) |
                (static_cast<Adesk::Int32>(b));
        }
    }
#else
    for (int i = 0; i < numPixels; ++i)
    {
        unsigned char r = rgbData[i * 3 + 0];
        unsigned char g = rgbData[i * 3 + 1];
        unsigned char b = rgbData[i * 3 + 2];
        unsigned char a = 0xFF; // Default fully opaque

        if (hasAlpha && alphaData) {
            // AutoCAD docs: 0x00 = transparent, 0xFF = opaque. 
            // Intermediate values not supported, so thresholding can be applied if needed.
            a = alphaData[i];
        }

        // Pack into an ARGB 32-bit longword
        // Bit shifts ensure the true color longword is structured correctly regardless of memory endianness
        argbBuffer[i] = (static_cast<Adesk::Int32>(a) << 24) |
            (static_cast<Adesk::Int32>(r) << 16) |
            (static_cast<Adesk::Int32>(g) << 8) |
            (static_cast<Adesk::Int32>(b));
    }
#endif
    // Call native AutoCAD/BricsCAD API
    Adesk::Boolean result = acgsDisplayImage(
        viewportNumber,
        originLeft,
        originBottom + imageHeight,
        imageWidth,
        imageHeight,
        static_cast<const void*>(argbBuffer.data()),
        hasAlpha ? 1 : 0
    );

    return (result == Adesk::kTrue);
#endif
}

struct SlideBounds {
    int16_t minX, maxX, minY, maxY;
};

//------------------------------------------------------------------------------
//GsCore::slideToWxImage
using ExtractColorCallback = void (*)(uint8_t, wxPen&, wxMemoryDC&);

static void ExtractColor(uint8_t lowByte, wxPen& currentPen, wxMemoryDC& mdc)
{
    static const unsigned char aciLUT[256][3] = {
        {255,255,255}, {255,0,0},     {255,255,0},   {0,255,0},     {0,255,255},   {0,0,255},     {255,0,255},   {255,255,255},
        {128,128,128}, {192,192,192}, {255,0,0},     {255,127,127}, {204,0,0},     {204,102,102}, {153,0,0},     {153,76,76},
        {102,0,0},     {102,51,51},   {51,0,0},      {51,25,25},    {255,63,0},    {255,159,127}, {204,51,0},    {204,127,102},
        {153,38,0},    {153,95,76},   {102,25,0},    {102,63,51},   {51,12,0},     {51,31,25},    {255,127,0},   {255,191,127},
        {204,102,0},   {204,153,102}, {153,76,0},    {153,114,76},  {102,51,0},    {102,76,51},   {51,25,0},     {51,38,25},
        {255,191,0},   {255,223,127}, {204,153,0},   {204,178,102}, {153,114,0},   {153,133,76},  {102,76,0},    {102,89,51},
        {51,38,0},     {51,44,25},    {255,255,0},   {255,255,127}, {204,204,0},   {204,204,102}, {153,153,0},   {153,153,76},
        {102,102,0},   {102,102,51},  {51,51,0},     {51,51,25},    {191,255,0},   {223,255,127}, {153,204,0},   {178,204,102},
        {114,153,0},   {133,153,76},  {76,102,0},    {89,102,51},   {38,51,0},     {44,51,25},    {127,255,0},   {191,255,127},
        {102,204,0},   {153,204,102}, {76,153,0},    {114,153,76},  {51,102,0},    {76,102,51},   {25,51,0},     {38,51,25},
        {63,255,0},    {159,255,127}, {51,204,0},    {127,204,102}, {38,153,0},    {95,153,76},   {25,102,0},    {63,102,51},
        {12,51,0},     {31,51,25},    {0,255,0},     {127,255,127}, {0,204,0},     {102,204,102}, {0,153,0},     {76,153,76},
        {0,102,0},     {51,102,51},   {0,51,0},      {25,51,25},    {0,255,63},    {127,255,159}, {0,204,51},    {102,204,127},
        {0,153,38},    {76,153,95},   {0,102,25},    {51,102,63},   {0,51,12},     {25,51,31},    {0,255,127},   {127,255,191},
        {0,204,102},   {102,204,153}, {0,153,76},    {76,153,114},  {0,102,51},    {51,102,76},   {0,51,25},     {25,51,38},
        {0,255,191},   {127,255,223}, {0,204,153},   {102,204,178}, {0,153,114},   {76,153,133},  {0,102,76},    {51,102,89},
        {0,51,38},     {25,51,44},    {0,255,255},   {127,255,255}, {0,204,204},   {102,204,204}, {0,153,153},   {76,153,153},
        {0,102,102},   {51,102,102},  {0,51,51},     {25,51,25},    {0,191,255},   {127,223,255}, {0,153,204},   {102,178,204},
        {0,114,153},   {76,133,153},  {0,76,102},    {51,89,102},   {0,38,51},     {25,44,51},    {0,127,255},   {127,191,255},
        {0,102,204},   {102,153,204}, {0,76,153},    {76,114,153},  {0,51,102},    {51,76,102},   {0,25,51},     {25,38,51},
        {0,63,255},    {127,159,255}, {0,51,204},    {102,127,204}, {0,38,153},    {76,95,153},   {0,25,102},    {51,63,102},
        {0,12,51},     {25,31,51},    {0,0,255},     {127,127,255}, {0,0,204},     {102,102,204}, {0,0,153},     {76,76,153},
        {0,0,102},     {51,51,102},   {0,0,51},      {25,25,51},    {63,0,255},    {159,127,255}, {51,0,204},    {127,102,204},
        {38,0,153},    {95,76,153},   {25,0,102},    {63,51,102},   {12,0,51},     {31,25,51},    {127,0,255},   {191,127,255},
        {102,0,204},   {153,102,204}, {76,0,153},    {76,114,153},  {0,51,102},    {51,76,102},   {25,0,51},     {38,25,51},
        {191,0,255},   {223,127,255}, {153,0,204},   {178,102,204}, {114,0,153},   {133,76,153},  {76,0,102},    {89,51,102},
        {38,0,51},     {44,25,51},    {255,0,255},   {255,127,255}, {204,0,204},   {204,102,204}, {153,0,153},   {153,76,153},
        {102,0,102},   {102,51,102},  {51,0,51},     {51,25,51},    {255,0,191},   {255,127,223}, {204,0,153},   {204,102,178},
        {153,0,114},   {153,76,133},  {102,0,76},    {102,51,89},   {51,0,38},     {51,25,44},    {255,0,127},   {255,127,191},
        {204,0,102},   {204,102,153}, {153,0,76},    {153,76,114},  {102,0,51},    {102,51,76},   {51,0,25},     {51,25,38},
        {255,0,63},    {255,127,159}, {204,0,51},    {204,102,127}, {153,0,38},    {153,76,95},   {102,0,25},    {102,51,63},
        {51,0,12},     {51,25,31},    {51,51,51},    {91,91,91},    {132,132,132}, {173,173,173}, {214,214,214}, {255,255,255}
    };
    wxColor penColor(aciLUT[lowByte][0], aciLUT[lowByte][1], aciLUT[lowByte][2]);
    currentPen.SetColour(penColor);
    mdc.SetPen(currentPen);
}

static SlideBounds parseSlideBounds(std::ifstream& file, std::streampos dataStartPos)
{
    file.clear();
    file.seekg(dataStartPos);

    int16_t minX = 32767, maxX = -32768;
    int16_t minY = 32767, maxY = -32768;

    int16_t lastX = 0; int16_t lastY = 0;
    int16_t firstWord = 0;

    auto updateBounds = [&](int16_t x, int16_t y) {
        if (x < minX) minX = x;
        if (x > maxX) maxX = x;
        if (y < minY) minY = y;
        if (y > maxY) maxY = y;
        };

    while (file.read(reinterpret_cast<char*>(&firstWord), 2)) {
        uint16_t uWord = static_cast<uint16_t>(firstWord);
        uint8_t highByte = (uWord & 0xFF00) >> 8;
        uint8_t lowByte = uWord & 0x00FF;

        bool isControlCode = false;
        if (highByte >= 0xFB) {
            std::streampos peekPos = file.tellg();
            if (highByte == 0xFF || highByte == 0xFC) isControlCode = true;
            else if (highByte == 0xFD) {
                int16_t fillX = 0, fillY = 0;
                if (file.read(reinterpret_cast<char*>(&fillX), 2) && file.read(reinterpret_cast<char*>(&fillY), 2)) isControlCode = true;
                file.seekg(peekPos);
            }
            else if (highByte == 0xFE) {
                int8_t dy = 0;
                if (file.read(reinterpret_cast<char*>(&dy), 1)) isControlCode = true;
                file.seekg(peekPos);
            }
            else if (highByte == 0xFB) {
                int8_t dy1 = 0, dx2 = 0, dy2 = 0;
                if (file.read(reinterpret_cast<char*>(&dy1), 1) && file.read(reinterpret_cast<char*>(&dx2), 1) && file.read(reinterpret_cast<char*>(&dy2), 1)) isControlCode = true;
                file.seekg(peekPos);
            }
        }

        if (isControlCode) {
            if (highByte == 0xFF) continue;
            if (highByte == 0xFC) break;

            if (highByte == 0xFD) {
                int16_t fillX = 0, fillY = 0;
                if (!file.read(reinterpret_cast<char*>(&fillX), 2) || !file.read(reinterpret_cast<char*>(&fillY), 2)) break;
                if (fillY < 0) file.seekg(fillX * 6, std::ios::cur);
                continue;
            }
            if (highByte == 0xFE) {
                int8_t rawDy = 0;
                if (!file.read(reinterpret_cast<char*>(&rawDy), 1)) break;

                int8_t dx = static_cast<int8_t>(lowByte);
                lastX += dx;
                lastY += rawDy;

                updateBounds(lastX, lastY);
                continue;
            }
            if (highByte == 0xFB) {
                int8_t rawDy1 = 0, rawDx2 = 0, rawDy2 = 0;
                if (!file.read(reinterpret_cast<char*>(&rawDy1), 1) ||
                    !file.read(reinterpret_cast<char*>(&rawDx2), 1) ||
                    !file.read(reinterpret_cast<char*>(&rawDy2), 1)) break;

                int8_t dx1 = static_cast<int8_t>(lowByte);
                int8_t dx2 = rawDx2;

                int16_t fromX = lastX + dx1;
                int16_t fromY = lastY + rawDy1;

                int16_t toX = fromX + dx2;
                int16_t toY = fromY + rawDy2;

                updateBounds(fromX, fromY);
                updateBounds(toX, toY);

                lastX = fromX; lastY = fromY;
                continue;
            }
        }
        else {
            int16_t y1 = 0, x2 = 0, y2 = 0;
            if (!file.read(reinterpret_cast<char*>(&y1), 2) || !file.read(reinterpret_cast<char*>(&x2), 2) || !file.read(reinterpret_cast<char*>(&y2), 2)) break;

            updateBounds(firstWord, y1);
            updateBounds(x2, y2);

            lastX = x2; lastY = y2;
            continue;
        }
    }

    if (maxX <= minX) { minX = 0; maxX = 1; }
    if (maxY <= minY) { minY = 0; maxY = 1; }
    return { minX, maxX, minY, maxY };
}

#ifdef NEVER  // TODO:
static void renderSolidFills(std::ifstream& file, std::streampos dataStartPos, wxMemoryDC& mdc,
    wxPen& currentPen, const wxColour& bkg, int width, int height,
    double scale, int offsetX, int offsetY,
    ExtractColorCallback extractColorCallback)
{
    file.clear();
    file.seekg(dataStartPos);
    uint16_t firstWord = 0;

    while (file.read(reinterpret_cast<char*>(&firstWord), 2)) {
        uint8_t lowByte = firstWord & 0x00FF;
        uint8_t highByte = (firstWord & 0xFF00) >> 8;

        if (highByte == 0xFF) {
            extractColorCallback(lowByte, currentPen, mdc);
            continue;
        }
        if (highByte == 0xFC) break; // End of file marker

        if (highByte == 0xFD) {
            int16_t fillX = 0, fillY = 0;
            if (!file.read(reinterpret_cast<char*>(&fillX), 2) ||
                !file.read(reinterpret_cast<char*>(&fillY), 2)) {
                break;
            }

            wxBrush fillBrush(currentPen.GetColour());
            wxBrush oldBrush = mdc.GetBrush();
            mdc.SetBrush(fillBrush);

            if (fillY < 0) {
                int16_t vertexCount = fillX;

                // Safety check: Prevent memory allocation crashes or file parsing desyncs
                if (vertexCount <= 0 || vertexCount > 1000) {
                    mdc.SetBrush(oldBrush);
                    break;
                }

                std::vector<wxPoint> points;
                points.reserve(vertexCount);
                bool readSuccess = true;

                // Read all vertices sequentially from the stream
                for (int16_t i = 0; i < vertexCount; ++i) {
                    int16_t vx = 0, vy = 0;

                    if (!file.read(reinterpret_cast<char*>(&vx), 2) ||
                        !file.read(reinterpret_cast<char*>(&vy), 2)) {
                        readSuccess = false;
                        break;
                    }

                    // Correct Cartesian to Screen Coordinates Conversion
                    int screenX = offsetX + static_cast<int>(vx * scale);
                    int screenY = height - (offsetY + static_cast<int>(vy * scale));

                    points.push_back(wxPoint(screenX, screenY));
                }

                if (!readSuccess) {
                    mdc.SetBrush(oldBrush);
                    break;
                }

                // Render by cleanly drawing the two structural triangular halves
                if (!points.empty()) {
                    wxPen oldPen = mdc.GetPen();
                    mdc.SetPen(*wxTRANSPARENT_PEN);

                    if (points.size() == 4) {
                        // Wedge 1 (Triangle A)
                        wxPoint tri1[3] = { points[0], points[1], points[2] };
                        mdc.DrawPolygon(3, tri1);

                        // Wedge 2 (Triangle B)
                        wxPoint tri2[3] = { points[1], points[2], points[3] };
                        mdc.DrawPolygon(3, tri2);
                    }
                    else {
                        // Standard fallback for native 3-point solid fills
                        mdc.DrawPolygon(static_cast<int>(points.size()), points.data());
                    }

                    mdc.SetPen(oldPen);
                }
            }
            else {
                // Standalone legacy FloodFill layout block
                int sFillX = offsetX + static_cast<int>(fillX * scale);
                int sFillY = height - (offsetY + static_cast<int>(fillY * scale));
                if (sFillX >= 0 && sFillX < width && sFillY >= 0 && sFillY < height) {
                    mdc.FloodFill(sFillX, sFillY, bkg, wxFLOOD_SURFACE);
                }
            }

            mdc.SetBrush(oldBrush);
            continue;
        }

        // Handle standard non-fill chunk skipping
        if (highByte == 0xFE)
            file.seekg(1, std::ios::cur);
        else if (highByte == 0xFB)
            file.seekg(3, std::ios::cur);
        else if (highByte <= 0xFA)
            file.seekg(2, std::ios::cur);
    }
}
#endif

static void renderVectors(std::ifstream& file, std::streampos dataStartPos, wxMemoryDC& mdc,
    wxPen& currentPen, int height, double scale, int offsetX, int offsetY,
    ExtractColorCallback extractColorCallback)
{
    file.clear();
    file.seekg(dataStartPos);

    int16_t anchorX = 0; int16_t anchorY = 0;
    int16_t currentX = 0; int16_t currentY = 0;
    int16_t firstWord = 0;

    currentPen.SetColour(*wxWHITE);
    mdc.SetPen(currentPen);

    while (file.read(reinterpret_cast<char*>(&firstWord), 2)) {
        uint16_t uWord = static_cast<uint16_t>(firstWord);
        uint8_t lowByte = uWord & 0x00FF;
        uint8_t highByte = (uWord & 0xFF00) >> 8;

        bool isControlCode = false;
        if (highByte >= 0xFB) {
            std::streampos peekPos = file.tellg();
            if (highByte == 0xFF || highByte == 0xFC) isControlCode = true;
            else if (highByte == 0xFD) {
                int16_t fillX = 0, fillY = 0;
                if (file.read(reinterpret_cast<char*>(&fillX), 2) && file.read(reinterpret_cast<char*>(&fillY), 2)) isControlCode = true;
                file.seekg(peekPos);
            }
            else if (highByte == 0xFE) {
                int8_t dy = 0;
                if (file.read(reinterpret_cast<char*>(&dy), 1)) isControlCode = true;
                file.seekg(peekPos);
            }
            else if (highByte == 0xFB) {
                int8_t dy1 = 0, dx2 = 0, dy2 = 0;
                if (file.read(reinterpret_cast<char*>(&dy1), 1) && file.read(reinterpret_cast<char*>(&dx2), 1) && file.read(reinterpret_cast<char*>(&dy2), 1)) isControlCode = true;
                file.seekg(peekPos);
            }
        }

        if (isControlCode) {
            if (highByte == 0xFF) {
                extractColorCallback(lowByte, currentPen, mdc);
                currentX = anchorX; currentY = anchorY;
                continue;
            }
            if (highByte == 0xFC) break;

            if (highByte == 0xFD) {
                int16_t fillX = 0, fillY = 0;
                file.read(reinterpret_cast<char*>(&fillX), 2);
                file.read(reinterpret_cast<char*>(&fillY), 2);
                if (fillY < 0) file.seekg(fillX * 6, std::ios::cur);
                currentX = anchorX; currentY = anchorY;
                continue;
            }

            if (highByte == 0xFE) {
                int8_t rawDy = 0;
                file.read(reinterpret_cast<char*>(&rawDy), 1);

                int sx1 = offsetX + static_cast<int>(currentX * scale);
                int sy1 = height - (offsetY + static_cast<int>(currentY * scale));

                int8_t dx = static_cast<int8_t>(lowByte);

                currentX += dx;
                currentY += rawDy;

                int sx2 = offsetX + static_cast<int>(currentX * scale);
                int sy2 = height - (offsetY + static_cast<int>(currentY * scale));

#if defined(_BRXTARGET)
                // COMPILE FIXED DIRECTION SWITCH: Corrects BricsCAD's vertical output layout
                sy1 = height - sy1;
                sy2 = height - sy2;
#endif

                mdc.DrawLine(sx1, sy1, sx2, sy2);
                continue;
            }

            if (highByte == 0xFB) {
                int8_t rawDy1 = 0, rawDx2 = 0, rawDy2 = 0;
                file.read(reinterpret_cast<char*>(&rawDy1), 1);
                file.read(reinterpret_cast<char*>(&rawDx2), 1);
                file.read(reinterpret_cast<char*>(&rawDy2), 1);

                int8_t dx1 = static_cast<int8_t>(lowByte);
                int8_t dx2 = rawDx2;

                int16_t fromX = currentX + dx1;
                int16_t fromY = currentY + rawDy1;

                int16_t toX = fromX + dx2;
                int16_t toY = fromY + rawDy2;

                int sx1 = offsetX + static_cast<int>(fromX * scale);
                int sy1 = height - (offsetY + static_cast<int>(fromY * scale));

                int sx2 = offsetX + static_cast<int>(toX * scale);
                int sy2 = height - (offsetY + static_cast<int>(toY * scale));

#if defined(_BRXTARGET)
                // COMPILE FIXED DIRECTION SWITCH: Corrects BricsCAD's vertical output layout
                sy1 = height - sy1;
                sy2 = height - sy2;
#endif

                mdc.DrawLine(sx1, sy1, sx2, sy2);

                currentX = fromX;
                currentY = fromY;
                continue;
            }
        }
        else {
            int16_t y1 = 0, x2 = 0, y2 = 0;
            if (!file.read(reinterpret_cast<char*>(&y1), 2) || !file.read(reinterpret_cast<char*>(&x2), 2) || !file.read(reinterpret_cast<char*>(&y2), 2)) break;

            int sx1 = offsetX + static_cast<int>(firstWord * scale);
            int sy1 = height - (offsetY + static_cast<int>(y1 * scale));

            int sx2 = offsetX + static_cast<int>(x2 * scale);
            int sy2 = height - (offsetY + static_cast<int>(y2 * scale));

            mdc.DrawLine(sx1, sy1, sx2, sy2);

            anchorX = x2; anchorY = y2;
            currentX = anchorX; currentY = anchorY;
            continue;
        }
    }
}


PyObject* GsCore::slideToWxImage(const std::string& sld_path, int width, int height, const boost::python::object& rgb)
{
    wxBitmap bitmap(width, height);
    wxMemoryDC mdc(bitmap);
    wxColour bkg(49, 56, 66);
    auto _rgb = PyListToInt32Array(rgb);

    if (_rgb.length() >= 3)
    {
        bkg.Set(static_cast<unsigned char>(_rgb[0]),
            static_cast<unsigned char>(_rgb[1]),
            static_cast<unsigned char>(_rgb[2]));
    }
    wxBrush backgroundBrush(bkg);
    mdc.SetBackground(backgroundBrush);
    mdc.Clear();

    wxPen currentPen(*wxWHITE, 1);
    mdc.SetPen(currentPen);

    std::ifstream file(sld_path, std::ios::binary);
    if (!file.is_open()) {
        return wxPyConstructObject((void*)new wxImage(width, height), wxT("wxImage"), true);
    }

    char header[31];
    file.read(header, 31);
    if (file.gcount() < 31 || std::string(header, 13) != "AutoCAD Slide") {
        return wxPyConstructObject((void*)new wxImage(width, height), wxT("wxImage"), true);
    }

    std::streampos dataStartPos = file.tellg();

    SlideBounds bounds = parseSlideBounds(file, dataStartPos);

    int drawingWidth = bounds.maxX - bounds.minX;
    int drawingHeight = bounds.maxY - bounds.minY;

    double paddingFactor = 0.90;
    double scaleX = (width * paddingFactor) / drawingWidth;
    double scaleY = (height * paddingFactor) / drawingHeight;
    double scale = std::min(scaleX, scaleY);

    // RESTORED: Stable, standard spatial calculation math across both targets
    int offsetX = static_cast<int>((width - (drawingWidth * scale)) / 2.0) - static_cast<int>(bounds.minX * scale);
    int offsetY = static_cast<int>((height - (drawingHeight * scale)) / 2.0) - static_cast<int>(bounds.minY * scale);

    mdc.SetBrush(*wxTRANSPARENT_BRUSH);

#ifdef NEVER  // TODO:
    renderSolidFills(file, dataStartPos, mdc, currentPen, bkg, width, height, scale, offsetX, offsetY, ExtractColor);
#endif

    renderVectors(file, dataStartPos, mdc, currentPen, height, scale, offsetX, offsetY, ExtractColor);

    file.close();
    mdc.SelectObject(wxNullBitmap);
    wxImage* finalImage = new wxImage(bitmap.ConvertToImage());
    return wxPyConstructObject((void*)finalImage, wxT("wxImage"), true);
}
