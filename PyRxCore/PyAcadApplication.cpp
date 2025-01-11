#include "stdafx.h"
#include "PyAcadApplication.h"
#include "PyAcadApplicationImpl.h"

#ifdef PYRX_IN_PROGRESS_PYAX
bool PyAcadApplication::runTest(const AcDbObjectId& id)
{
    return PyAcadApplicationImpl::runTest(id);
}
#endif