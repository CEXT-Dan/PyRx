#include "stdafx.h"
#include "stdafx.h"
#include "GsCore.h"
#include "PyGsView.h"
#include "PyDbObjectId.h"
#include "Image.h"


using namespace boost::python;

void makeGsCoreWrapper()
{
    PyDocString DS("Core");
    class_<GsCore>("Core")
        .def("getCurrentAcGsView", &GsCore::getCurrentAcGsView, DS.SARGS({ "vpNum : int" })).staticmethod("getCurrentAcGsView")
        .def("getCurrent3DAcGsView", &GsCore::getCurrent3DAcGsView, DS.SARGS({ "vpNum : int" })).staticmethod("getCurrent3DAcGsView")
        .def("getViewParameters", &GsCore::getViewParameters, DS.SARGS({ "vpNum : int", "view : PyGs.View"})).staticmethod("getViewParameters")
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

wxImage GsCore::getBlockImage(const PyDbObjectId& blkid, int x, int y)
{
    wxImage wximage;
#ifdef PYRXDEBUG
    AcGsKernelDescriptor descriptor;
    descriptor.addRequirement(AcGsKernelDescriptor::k3DDrawing);
    AcGsGraphicsKernel* pGraphicsKernel = AcGsManager::acquireGraphicsKernel(descriptor);
    if (pGraphicsKernel == nullptr)
        return wximage;

    AcGsDevice* pOffDevice = pGraphicsKernel->createOffScreenDevice();
    AcGsModel* pModel = acgsGetGsManager()->createAutoCADModel(*pGraphicsKernel);

    AcGsView* view = acgsGetGsManager()->createView(pOffDevice);
    pOffDevice->add(view);

    AcDbBlockTableRecordPointer pBlock(blkid.m_id);

    Atil::Image* i = new Atil::Image();
    

    view->add(pBlock, pModel);
    //view->getSnapShot()
    Atil::Image* image = view->createSnapshot(AcGsDCPoint(0, 0), AcGsDCRect(0, 0, x, y), GS::ImageDataFormat::kRGBA, GS::kTopDown);
    view->eraseAll();
    pOffDevice->eraseAll();

    pGraphicsKernel->deleteView(view);
    pGraphicsKernel->deleteModel(pModel);
#else
    PyThrowBadEs(Acad::eNotImplementedYet);
#endif
    return wximage;
}
