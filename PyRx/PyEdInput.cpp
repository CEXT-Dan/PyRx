#include "stdafx.h"
#include "PyEdInput.h"
#include "PyApDocument.h"

//---------------------------------------------------------------------------------
//AcEdInputPointManager
PyEdInputPointManager::PyEdInputPointManager(AcEdInputPointManager* src)
    : m_pyImp(src)
{
}

PyEdInputPointManager::~PyEdInputPointManager()
{
    m_pyImp = nullptr;
}

void PyEdInputPointManager::registerPointFilter(PyEdInputPointFilter& pFilter)
{
   PyThrowBadEs(impObj()->registerPointFilter(pFilter.impObj()));
}

void PyEdInputPointManager::revokePointFilter()
{
    PyThrowBadEs(impObj()->revokePointFilter());//TODO test!
}

bool PyEdInputPointManager::hasFilter()
{
    return impObj()->currentPointFilter() != nullptr;
}

void PyEdInputPointManager::addPointMonitor(PyEdInputPointMonitor& pMonitor)
{
    PyThrowBadEs(impObj()->addPointMonitor(pMonitor.impObj()));
}

void PyEdInputPointManager::removePointMonitor(PyEdInputPointMonitor& pMonitor)
{
    PyThrowBadEs(impObj()->removePointMonitor(pMonitor.impObj()));
}

bool PyEdInputPointManager::disableSystemCursorGraphics()
{
    return impObj()->disableSystemCursorGraphics() == eOk;
}

bool PyEdInputPointManager::enableSystemCursorGraphics()
{
    return impObj()->enableSystemCursorGraphics() == eOk;
}

int PyEdInputPointManager::systemCursorDisableCount() const
{
    return impObj()->systemCursorDisableCount();
}

bool PyEdInputPointManager::turnOffForcedPick()
{
    return impObj()->turnOffForcedPick() == eOk;
}

int PyEdInputPointManager::forcedPickCount() const
{
    return impObj()->forcedPickCount();
}

int PyEdInputPointManager::mouseHasMoved() const
{
    return impObj()->mouseHasMoved();
}

bool PyEdInputPointManager::turnOnSubentityWindowSelection()
{
    return impObj()->turnOnSubentityWindowSelection() == eOk;
}

bool PyEdInputPointManager::turnOffSubentityWindowSelection()
{
    return impObj()->turnOffSubentityWindowSelection() == eOk;
}

void PyEdInputPointManager::enableMultiSubentPathSelection(bool bEnable)
{
    return impObj()->enableMultiSubentPathSelection(bEnable);
}

AcEdInputPointManager* PyEdInputPointManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return m_pyImp;
}

//---------------------------------------------------------------------------------
//PyEdInputPointFilterImpl
PyEdInputPointFilterImpl::PyEdInputPointFilterImpl(PyEdInputPointFilter* bckPtr)
    : m_bckPtr(bckPtr)
{

}

Acad::ErrorStatus PyEdInputPointFilterImpl::processInputPoint(const AcEdInputPoint& input, AcEdInputPointFilterResult& output)
{
    return eOk;
}

PyEdInputPointFilter* PyEdInputPointFilterImpl::backPtr(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_bckPtr == nullptr)
        throw PyNullObject(src);
    return m_bckPtr;
}

//---------------------------------------------------------------------------------
//PyEdInputPointMonitorImpl
PyEdInputPointMonitorImpl::PyEdInputPointMonitorImpl(PyEdInputPointMonitor* bckPtr)
    : m_bckPtr(bckPtr)
{

}

Acad::ErrorStatus PyEdInputPointMonitorImpl::monitorInputPoint(const AcEdInputPoint& input, AcEdInputPointMonitorResult& output)
{
    PyAutoLockGIL lock;
    PyEdInputPoint pyinput(input);
    PyEdInputPointMonitorResult pyoutput(output);
    return backPtr()->monitorInputPoint(pyinput, pyoutput);
}

PyEdInputPointMonitor* PyEdInputPointMonitorImpl::backPtr(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_bckPtr == nullptr)
        throw PyNullObject(src);
    return m_bckPtr;
}

//---------------------------------------------------------------------------------
//PyEdInputPointFilter
PyEdInputPointFilter::PyEdInputPointFilter()
    : PyRxObject(new PyEdInputPointFilterImpl(this),true,false)
{

}

Acad::ErrorStatus PyEdInputPointFilter::monitorInputPoint(const PyEdInputPoint& input, PyEdInputPointFilterResult& output)
{
    return eOk;
}

PyEdInputPointFilterImpl* PyEdInputPointFilter::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<PyEdInputPointFilterImpl*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------
//PyEdInputPointMonitor
PyEdInputPointMonitor::PyEdInputPointMonitor()
    : PyRxObject(new PyEdInputPointMonitorImpl(this), true, false)
{

}

Acad::ErrorStatus PyEdInputPointMonitor::monitorInputPoint(const PyEdInputPoint& input, PyEdInputPointMonitorResult& output)
{
    return eOk;
}

PyEdInputPointMonitorImpl* PyEdInputPointMonitor::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<PyEdInputPointMonitorImpl*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------
//PyEdInputPoint
PyEdInputPoint::PyEdInputPoint(const AcEdInputPoint& inp)
    : rpyimp(inp)
{
}

//---------------------------------------------------------------------------------
//PyEdInputPointFilterResult
PyEdInputPointFilterResult::PyEdInputPointFilterResult(AcEdInputPointFilterResult& inpr)
  : rpyimp(inpr)
{
}

//---------------------------------------------------------------------------------
//PyEdInputPointMonitorResult
PyEdInputPointMonitorResult::PyEdInputPointMonitorResult(AcEdInputPointMonitorResult& inpr)
    : rpyimp(inpr)
{
}
