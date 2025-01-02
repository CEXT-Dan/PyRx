#include "stdafx.h"
#include "PyAxApplicationImpl.h"


#ifdef PYRXDEBUG

#if defined(_ARXTARGET)
#include "axboiler.h"
#endif

PyAxApplicationImpl::PyAxApplicationImpl()
 : m_pyimp(acedGetIDispatch(FALSE))
{
}


#endif