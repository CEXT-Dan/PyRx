#pragma once
#include "acgs.h"

#if defined(_ZRXTARGET250) || defined(_GRXTARGET250)
//ZWCAD24 'register' is no longer a supported storage class
#pragma warning( disable: 5033 )
#endif
#include "Image.h"
#include "RgbModel.h"
#include "RgbGrayModel.h"
#include "RgbPaletteModel.h"
#include "codec_properties/FormatCodecPropertyInterface.h"
#include "format_codecs/BmpFormatCodec.h"
#include "RowProviderInterface.h"
#include "FileWriteDescriptor.h"
#include "DataBuffer.h"
#if defined(_ZRXTARGET250) || defined(_GRXTARGET250)
#pragma warning( pop )
#endif

#pragma pack (push, 8)
class PyGsView;
class PyDbObjectId;

struct AcGsDeviceDeleter
{
    void operator()(AcGsDevice* ptr);
};
using AcGsDevicePtr = std::unique_ptr <AcGsDevice, AcGsDeviceDeleter>;

struct AcGsViewDeleter
{
    void operator()(AcGsView* ptr);
};
using AcGsViewPtr = std::unique_ptr <AcGsView, AcGsViewDeleter>;

struct AcGsModelDeleter
{
    void operator()(AcGsModel* ptr);
};
using AcGsModelPtr = std::unique_ptr <AcGsModel, AcGsModelDeleter>;

class BlockImageRenderer
{
public:
    BlockImageRenderer(int width, int height, boost::python::object& rgb);
    bool isValid() const;
    wxImage render(AcDbBlockTableRecord* pBlock, double zoomFactor);

private:
    AcGsGraphicsKernel* m_pGraphicsKernel;
    AcGsDevicePtr m_pOffDevice;
    AcGsViewPtr m_pView;
    AcGsModelPtr m_pModel;
    int m_width;
    int m_height;
    bool m_isReady;
    Atil::RgbModel m_rgbModel;
    Atil::ImagePixel m_initialColor;
    AcGeVector3d m_upvector;
};

//------------------------------------------------------------------------------------
//GsCore
void makeGsCoreWrapper();

class GsCore
{
public:
    static PyGsView getCurrentAcGsView(int vpNum);
    static PyGsView getCurrent3DAcGsView(int vpNum);
    static bool getViewParameters(int vpNum, PyGsView& view);
    static bool setViewParameters1(int viewportNumber, const PyGsView& obj, bool bRegenRequired, bool bRescaleRequired);
    static bool setViewParameters2(int viewportNumber, const PyGsView& obj, bool bRegenRequired, bool bRescaleRequired, bool bSyncRequired);
    static PyObject* getBlockImage(const PyDbObjectId& blkid, int x, int y, double zf, boost::python::object& rgb);
    static boost::python::list getBlockImages(const boost::python::list& blkid, int x, int y, double zf, boost::python::object& rgb);
};

#pragma pack (pop)
