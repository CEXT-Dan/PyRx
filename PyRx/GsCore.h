#pragma once
#include "acgs.h"

class PyGsView;
class PyDbObjectId;


void makeGsCoreWrapper();

class GsCore
{
public:
   static PyGsView getCurrentAcGsView(int vpNum);
   static PyGsView getCurrent3DAcGsView(int vpNum);
   static bool getViewParameters(int vpNum, PyGsView& view);
   static bool setViewParameters1(int viewportNumber, const PyGsView& obj, bool bRegenRequired, bool bRescaleRequired);
   static bool setViewParameters2(int viewportNumber, const PyGsView& obj, bool bRegenRequired, bool bRescaleRequired, bool bSyncRequired);
   static PyObject* getBlockImage(const PyDbObjectId& blkid, int x, int y, boost::python::object& rgb);
};

