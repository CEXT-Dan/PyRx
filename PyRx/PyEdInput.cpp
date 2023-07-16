#include "stdafx.h"
#include "PyEdInput.h"
#include "PyApDocument.h"
#include "PyGiCommonDraw.h"
#include "PyDbObjectId.h"
#include "PyGeCurve3d.h"

using namespace boost::python;

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
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("monitorInputPoint"))
            return f(input, output);
    }
    catch (...)
    {
        throw PyAcadErrorStatus(Acad::ErrorStatus::eInvalidInput);
    }
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
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("monitorInputPoint"))
            return f(input, output);
    }
    catch (...)
    {
        throw PyAcadErrorStatus(Acad::ErrorStatus::eInvalidInput);
    }
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

PyApDocument PyEdInputPoint::document() const
{
    return PyApDocument(rpyimp.document(),false);
}

bool PyEdInputPoint::pointComputed() const
{
   return rpyimp.pointComputed();
}

int PyEdInputPoint::history() const
{
    return rpyimp.history();
}

AcGePoint3d PyEdInputPoint::lastPoint() const
{
    return rpyimp.lastPoint();
}

AcGePoint3d PyEdInputPoint::rawPoint() const
{
    return rpyimp.rawPoint();
}

AcGePoint3d PyEdInputPoint::grippedPoint() const
{
    return rpyimp.grippedPoint();
}

AcGePoint3d PyEdInputPoint::cartesianSnappedPoint() const
{
    return rpyimp.cartesianSnappedPoint();
}

AcGePoint3d PyEdInputPoint::osnappedPoint() const
{
    return rpyimp.osnappedPoint();
}

AcDb::OsnapMask PyEdInputPoint::osnapMask() const
{
    return rpyimp.osnapMask();
}

AcDb::OsnapMask PyEdInputPoint::osnapOverrides() const
{
    return rpyimp.osnapOverrides();
}

boost::python::list PyEdInputPoint::pickedEntities() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const auto& resut = rpyimp.pickedEntities();
    for (const auto& item : resut)
        pyList.append(PyDbObjectId(item));
    return pyList;
}

boost::python::list PyEdInputPoint::nestedPickedEntities() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const auto& resut = rpyimp.nestedPickedEntities();
    for (const auto& items : resut)
    {
        boost::python::list pysubList;
        for(const auto& item : items)
            pysubList.append(PyDbObjectId(item));
        pyList.append(pysubList);
    }
    return pyList;
}

boost::python::list PyEdInputPoint::gsSelectionMark() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const auto& resut = rpyimp.gsSelectionMark();
    for (const auto item : resut)
        pyList.append(item);
    return pyList;
}

boost::python::list PyEdInputPoint::keyPointEntities() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const auto& resut = rpyimp.keyPointEntities();
    for (const auto& item : resut)
        pyList.append(PyDbObjectId(item));
    return pyList;
}

boost::python::list PyEdInputPoint::nestedKeyPointEntities() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const auto& resut = rpyimp.nestedKeyPointEntities();
    for (const auto& items : resut)
    {
        boost::python::list pysubList;
        for (const auto& item : items)
            pysubList.append(PyDbObjectId(item));
        pyList.append(pysubList);
    }
    return pyList;
}

boost::python::list PyEdInputPoint::keyPointGsSelectionMark() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const auto& resut = rpyimp.keyPointGsSelectionMark();
    for (const auto item : resut)
        pyList.append(item);
    return pyList;
}

boost::python::list PyEdInputPoint::alignmentPaths() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const auto& resut = rpyimp.alignmentPaths();
    for (auto& item : resut)
        pyList.append(PyGeCurve3d(item));
    return pyList;
}

AcGePoint3d PyEdInputPoint::computedPoint() const
{
    return rpyimp.computedPoint();
}

std::string PyEdInputPoint::tooltipString() const
{
    return wstr_to_utf8(rpyimp.tooltipString());
}

PyGiViewportDraw PyEdInputPoint::drawContext() const
{
    return PyGiViewportDraw(rpyimp.drawContext(), false);
}

//---------------------------------------------------------------------------------
//PyEdInputPointFilterResult
PyEdInputPointFilterResult::PyEdInputPointFilterResult(AcEdInputPointFilterResult& inpr)
  : rpyimp(inpr)
{
}

void PyEdInputPointFilterResult::setNewPoint(const AcGePoint3d& newValue)
{
    rpyimp.setNewPoint(newValue);
}

void PyEdInputPointFilterResult::setDisplayOsnapGlyph(bool newValue)
{
    rpyimp.setDisplayOsnapGlyph(newValue);
}

void PyEdInputPointFilterResult::setNewTooltipString(const std::string& newValue)
{
    rpyimp.setNewTooltipString(utf8_to_wstr(newValue).c_str());
}

void PyEdInputPointFilterResult::setRetry(bool newValue)
{
    rpyimp.setRetry(newValue);
}

AcGePoint3d PyEdInputPointFilterResult::newPoint() const
{
    return rpyimp.newPoint();
}

bool PyEdInputPointFilterResult::displayOsnapGlyph() const
{
    return rpyimp.displayOsnapGlyph();
}

std::string PyEdInputPointFilterResult::newTooltipString() const
{
    return wstr_to_utf8(rpyimp.newTooltipString());
}

bool PyEdInputPointFilterResult::retry() const
{
    return rpyimp.retry();
}

//---------------------------------------------------------------------------------
//PyEdInputPointMonitorResult
PyEdInputPointMonitorResult::PyEdInputPointMonitorResult(AcEdInputPointMonitorResult& inpr)
    : rpyimp(inpr)
{
}

void PyEdInputPointMonitorResult::setAdditionalTooltipString(const std::string& newValue)
{
    rpyimp.setAdditionalTooltipString(utf8_to_wstr(newValue).c_str());
}

bool PyEdInputPointMonitorResult::appendToTooltipStr() const
{
    return rpyimp.appendToTooltipStr();
}

std::string PyEdInputPointMonitorResult::additionalTooltipString() const
{
    return wstr_to_utf8(rpyimp.additionalTooltipString());
}
