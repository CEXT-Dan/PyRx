#include "stdafx.h"
#include "PyAcadApplication.h"
#include "PyAcadApplicationImpl.h"

#ifdef PYRXDEBUG
bool PyAcadApplication::runTest()
{
    return PyAcadApplicationImpl::runTest();
}
#endif