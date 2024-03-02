#pragma once
#include "acgs.h"

class PyGsView;


void makeGsCoreWrapper();

class GsCore
{
public:
   static PyGsView getCurrentAcGsView(int vpNum);
   static PyGsView getCurrent3DAcGsView(int vpNum);
  
};

