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
static void setBackgroundColorFromPy(AcGsDevice* pDevice, boost::python::object& rgb)
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

BlockImageRenderer::BlockImageRenderer(int width, int height, boost::python::object& rgb)
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

        .def("slideToWxImage", &GsCore::slideToWxImage, DS.SARGS({ "path : str", "width : int",  "height : int" })).staticmethod("slideToWxImage")
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

boost::python::list GsCore::getBlockImages(const boost::python::list& blkids, int x, int y, double zf, boost::python::object& rgb)
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

PyObject* GsCore::slideToWxImage(const std::string& sld_path, int width, int height)
{
    wxBitmap bitmap(width, height);
    wxMemoryDC mdc(bitmap);

    mdc.SetBackground(*wxBLACK_BRUSH);
    mdc.Clear();

    wxPen currentPen(*wxWHITE, 1);
    mdc.SetPen(currentPen);

    std::ifstream file(sld_path, std::ios::binary);
    if (!file.is_open()) {
        return wxPyConstructObject((void*)new wxImage(width, height), wxT("wxImage"), true);
    }

    // 1. Read and validate the full 31-byte Header
    char header[31];
    file.read(header, 31);
    if (file.gcount() < 31 || std::string(header, 13) != "AutoCAD Slide") {
        return wxPyConstructObject((void*)new wxImage(width, height), wxT("wxImage"), true);
    }

    // Extract original coordinate limits from header (little-endian 16-bit ints)
    uint16_t highX = *reinterpret_cast<uint16_t*>(&header[19]); // Offset 19: High X dot
    uint16_t highY = *reinterpret_cast<uint16_t*>(&header[21]); // Offset 21: High Y dot

    // Avoid division by zero if header is corrupted
    if (highX == 0) highX = 1;
    if (highY == 0) highY = 1;

    // Keep track of the "last point" for relative/offset vector records
    int lastX = 0;
    int lastY = 0;

    // 2. Process variable-length data stream records
    uint16_t firstWord = 0;
    while (file.read(reinterpret_cast<char*>(&firstWord), 2)) {
        uint8_t lowByte = firstWord & 0x00FF;
        uint8_t highByte = (firstWord & 0xFF00) >> 8;

        // --- TYPE 1: Color Change Record (High Byte = 0xFF) ---
        if (highByte == 0xFF) {
            wxColor penColor;
            switch (lowByte) {
                case 1: penColor = *wxRED; break;
                case 2: penColor = *wxYELLOW; break;
                case 3: penColor = *wxGREEN; break;
                case 4: penColor = *wxCYAN; break;
                case 5: penColor = *wxBLUE; break;
                case 6: penColor = wxColour(255, 0, 255); break; // Magenta
                case 7: penColor = *wxWHITE; break;
                default: penColor = *wxWHITE; break;
            }
            currentPen.SetColour(penColor);
            mdc.SetPen(currentPen);
            continue; // 2 bytes total processed
        }

        // --- TYPE 2: End of File (High Byte = 0xFC) ---
        if (highByte == 0xFC) {
            break;
        }

        // --- TYPE 3: Common-endpoint Vector (High Byte = 0xFE) ---
        if (highByte == 0xFE) {
            int8_t dx = static_cast<int8_t>(lowByte);
            int8_t dy = 0;
            if (!file.read(reinterpret_cast<char*>(&dy), 1)) break;

            int newX = lastX + dx;
            int newY = lastY + dy;

            int sx1 = static_cast<int>((static_cast<double>(lastX) / highX) * width);
            int sy1 = height - static_cast<int>((static_cast<double>(lastY) / highY) * height);
            int sx2 = static_cast<int>((static_cast<double>(newX) / highX) * width);
            int sy2 = height - static_cast<int>((static_cast<double>(newY) / highY) * height);

            mdc.DrawLine(sx1, sy1, sx2, sy2);

            lastX = newX;
            lastY = newY;
            continue; // 3 bytes total processed
        }

        // --- TYPE 4: Offset Vector Record (High Byte = 0xFB) ---
        if (highByte == 0xFB) {
            int8_t dx1 = static_cast<int8_t>(lowByte);
            int8_t dy1 = 0;
            int8_t dx2 = 0;
            int8_t dy2 = 0;
            if (!file.read(reinterpret_cast<char*>(&dy1), 1) ||
                !file.read(reinterpret_cast<char*>(&dx2), 1) ||
                !file.read(reinterpret_cast<char*>(&dy2), 1)) {
                break;
            }

            int x1 = lastX + dx1;
            int y1 = lastY + dy1;
            int x2 = x1 + dx2;
            int y2 = y1 + dy2;

            int sx1 = static_cast<int>((static_cast<double>(x1) / highX) * width);
            int sy1 = height - static_cast<int>((static_cast<double>(y1) / highY) * height);
            int sx2 = static_cast<int>((static_cast<double>(x2) / highX) * width);
            int sy2 = height - static_cast<int>((static_cast<double>(y2) / highY) * height);

            mdc.DrawLine(sx1, sy1, sx2, sy2);

            lastX = x2;
            lastY = y2;
            continue; // 5 bytes total processed
        }

        // --- TYPE 5: Standard Vector Record (High Byte <= 0x7F) ---
        if (highByte <= 0x7F) {
            int16_t x1 = static_cast<int16_t>(firstWord);
            int16_t y1 = 0, x2 = 0, y2 = 0;

            if (!file.read(reinterpret_cast<char*>(&y1), 2) ||
                !file.read(reinterpret_cast<char*>(&x2), 2) ||
                !file.read(reinterpret_cast<char*>(&y2), 2)) {
                break;
            }

            // Correct mapping relative to original bounds extracted from the header
            int sx1 = static_cast<int>((static_cast<double>(x1) / highX) * width);
            int sy1 = height - static_cast<int>((static_cast<double>(y1) / highY) * height);
            int sx2 = static_cast<int>((static_cast<double>(x2) / highX) * width);
            int sy2 = height - static_cast<int>((static_cast<double>(y2) / highY) * height);

            mdc.DrawLine(sx1, sy1, sx2, sy2);

            // Save the starting point as the reference "last point" per spec
            lastX = x1;
            lastY = y1;
            continue; // 8 bytes total processed
        }
    }

    file.close();

    mdc.SelectObject(wxNullBitmap);
    wxImage* finalImage = new wxImage(bitmap.ConvertToImage());
    return wxPyConstructObject((void*)finalImage, wxT("wxImage"), true);
}
