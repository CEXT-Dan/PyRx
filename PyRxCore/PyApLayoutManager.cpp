#include "stdafx.h"
#include "PyApLayoutManager.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyApLayoutManagerWrapper()
{
    PyDocString DS("LayoutManager");
    class_<PyApLayoutManager, bases<PyDbLayoutManager>>("LayoutManager")
        .def(init<>(DS.ARGS(213)))
        .def("pageSetup", &PyApLayoutManager::pageSetup1)
        .def("pageSetup", &PyApLayoutManager::pageSetup2)
        .def("pageSetup", &PyApLayoutManager::pageSetup3, DS.ARGS({ "layoutBTRId : PyDb.ObjectId=PyDb.ObjectId.kNull","parent : int=0","isPageSetupDlg : bool=True" }, 219))
        .def("updateCurrentPaper", &PyApLayoutManager::updateCurrentPaper1)
        .def("updateCurrentPaper", &PyApLayoutManager::updateCurrentPaper2, DS.ARGS({ "zoomToPaper : bool=False" }, 234))
        .def("updateLayoutTabs", &PyApLayoutManager::updateLayoutTabs, DS.ARGS(235))
        .def("getActiveTab", &PyApLayoutManager::getActiveTab, DS.ARGS(217))
        .def("showTabs", &PyApLayoutManager::showTabs, DS.ARGS(233))
        .def("setShowTabs", &PyApLayoutManager::setShowTabs, DS.ARGS({ "show_tabs : bool" }, 228))
        .def("showPageSetup", &PyApLayoutManager::showPageSetup, DS.ARGS(229))
        .def("setShowPageSetup", &PyApLayoutManager::setShowPageSetup, DS.ARGS({ "show_page_setup : bool" }, 224))
        .def("createViewports", &PyApLayoutManager::createViewports, DS.ARGS(215))
        .def("setCreateViewports", &PyApLayoutManager::setCreateViewports, DS.ARGS({ "create_viewports : bool" }, 222))
        .def("showPaperBackground", &PyApLayoutManager::showPaperBackground, DS.ARGS(224))
        .def("setShowPaperBackground", &PyApLayoutManager::setShowPaperBackground, DS.ARGS({ "show_paper_background : bool" }, 225))
        .def("showPaperMargins", &PyApLayoutManager::showPaperMargins, DS.ARGS(231))
        .def("setShowPaperMargins", &PyApLayoutManager::setShowPaperMargins, DS.ARGS({ "show_paper_margins  : bool" }, 226))
        .def("showPrintBorder", &PyApLayoutManager::showPrintBorder, DS.ARGS(232))
        .def("setShowPrintBorder", &PyApLayoutManager::setShowPrintBorder, DS.ARGS({ "show_print_border : bool" }, 227))
        .def("generateNextNewLayoutName", &PyApLayoutManager::generateNextNewLayoutName1)
        .def("generateNextNewLayoutName", &PyApLayoutManager::generateNextNewLayoutName2, DS.ARGS({ "useDb : PyDb.Database=..." }, 216))
        .def("setDefaultPlotConfig", &PyApLayoutManager::setDefaultPlotConfig, DS.ARGS({ "id : PyDb.ObjectId" }, 223))
        .def("getClipBoundaryElabration", &PyApLayoutManager::getClipBoundaryElabration, DS.ARGS({ "id : PyDb.ObjectId" }))
        .def("pointInViewports", &PyApLayoutManager::pointInViewports, DS.ARGS({ "id : PyGe.Point3d" }, 220))
        .def("setCaptureOnLayoutSwitch", &PyApLayoutManager::setCaptureOnLayoutSwitch, DS.ARGS({ "id : bool" }, 221))
        .def("createLayoutFromTemplate", &PyApLayoutManager::createLayoutFromTemplate1)
        .def("createLayoutFromTemplate", &PyApLayoutManager::createLayoutFromTemplate2, DS.ARGS({ "newLayoutName : str","templatePath : str","layoutName : str","db : PyDb.Database=..." }, 214))
        .def("desc", &PyApLayoutManager::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyApLayoutManager::className, DS.SARGS()).staticmethod("className")
        ;
}

PyApLayoutManager::PyApLayoutManager()
    : PyApLayoutManager(dynamic_cast<AcApLayoutManager*>(acdbHostApplicationServices()->layoutManager()), false)
{
}

PyApLayoutManager::PyApLayoutManager(AcApLayoutManager* ptr, bool autoDelete)
    : PyDbLayoutManager(ptr, autoDelete)
{
}

int PyApLayoutManager::pageSetup1() const
{
    return impObj()->pageSetup();
}

int PyApLayoutManager::pageSetup2(const PyDbObjectId& lid) const
{
    return impObj()->pageSetup(lid.m_id);
}

int PyApLayoutManager::pageSetup3(const PyDbObjectId& lid, UINT_PTR wnd, Adesk::Boolean isPageSetupDlg) const
{
    return impObj()->pageSetup(lid.m_id, (void*)wnd, isPageSetupDlg);
}

void PyApLayoutManager::updateCurrentPaper1() const
{
    return impObj()->updateCurrentPaper();
}

void PyApLayoutManager::updateCurrentPaper2(Adesk::Boolean zoomToPaper) const
{
    return impObj()->updateCurrentPaper(zoomToPaper);
}

void PyApLayoutManager::updateLayoutTabs() const
{
    return impObj()->updateLayoutTabs();
}

std::string PyApLayoutManager::getActiveTab() const
{
    AcString sName;
    PyThrowBadEs(impObj()->getActiveTab(sName));
    return wstr_to_utf8(sName);
}

Adesk::Boolean PyApLayoutManager::showTabs() const
{
    return impObj()->showTabs();
}

void PyApLayoutManager::setShowTabs(Adesk::Boolean showTabs) const
{
    return impObj()->setShowTabs(showTabs);
}

Adesk::Boolean PyApLayoutManager::showPageSetup() const
{
    return impObj()->showPageSetup();
}

void PyApLayoutManager::setShowPageSetup(Adesk::Boolean showPageSetupDlg) const
{
    return impObj()->setShowPageSetup(showPageSetupDlg);
}

Adesk::Boolean PyApLayoutManager::createViewports() const
{
    return impObj()->createViewports();
}

void PyApLayoutManager::setCreateViewports(Adesk::Boolean createViewports) const
{
    return impObj()->setCreateViewports(createViewports);
}

Adesk::Boolean PyApLayoutManager::showPaperBackground() const
{
    return impObj()->showPaperBackground();
}

void PyApLayoutManager::setShowPaperBackground(Adesk::Boolean showPaperBackground) const
{
    return impObj()->setShowPaperBackground(showPaperBackground);
}

Adesk::Boolean PyApLayoutManager::showPaperMargins() const
{
    return impObj()->showPaperMargins();
}

void PyApLayoutManager::setShowPaperMargins(Adesk::Boolean showPaperMargins) const
{
    return impObj()->setShowPaperMargins(showPaperMargins);
}

Adesk::Boolean PyApLayoutManager::showPrintBorder() const
{
    return impObj()->showPrintBorder();
}

void PyApLayoutManager::setShowPrintBorder(Adesk::Boolean showPrintBorder) const
{
    return impObj()->setShowPrintBorder(showPrintBorder);
}

std::string PyApLayoutManager::generateNextNewLayoutName1() const
{
    AcString sName;
    PyThrowBadEs(impObj()->generateNextNewLayoutName(sName));
    return wstr_to_utf8(sName);
}

std::string PyApLayoutManager::generateNextNewLayoutName2(PyDbDatabase& useDb) const
{
    AcString sName;
    PyThrowBadEs(impObj()->generateNextNewLayoutName(sName, useDb.impObj()));
    return wstr_to_utf8(sName);
}

void PyApLayoutManager::setDefaultPlotConfig(PyDbObjectId& layoutBTRId) const
{
    return impObj()->setDefaultPlotConfig(layoutBTRId.m_id);
}

boost::python::list PyApLayoutManager::getClipBoundaryElabration(const PyDbObjectId& clipId) const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    AcGePoint2dArray* clipBoundary = nullptr;
    PyThrowBadEs(impObj()->getClipBoundaryElaboration(clipId.m_id, clipBoundary));
    if (clipBoundary != nullptr)
        return Point2dArrayToPyList(*clipBoundary);
    return pyList;
}

boost::python::list PyApLayoutManager::pointInViewports(const AcGePoint3d& pickPt) const
{
    AcDbObjectIdArray viewports;
    PyThrowBadEs(impObj()->pointInViewports(pickPt, viewports));
    return ObjectIdArrayToPyList(viewports);
}

void PyApLayoutManager::setCaptureOnLayoutSwitch(bool bCaptureOnLayout) const
{
    return impObj()->setCaptureOnLayoutSwitch(bCaptureOnLayout);
}

PyDbObjectId PyApLayoutManager::createLayoutFromTemplate1(const std::string& newLayoutName, const std::string& templatePath, const std::string& layoutName) const
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->createLayoutFromTemplate(utf8_to_wstr(newLayoutName).c_str(), id.m_id, utf8_to_wstr(templatePath).c_str(), utf8_to_wstr(layoutName).c_str()));
    return id;
}

PyDbObjectId PyApLayoutManager::createLayoutFromTemplate2(const std::string& newLayoutName, const std::string& templatePath, const std::string& layoutName, PyDbDatabase& pDb) const
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->createLayoutFromTemplate(utf8_to_wstr(newLayoutName).c_str(), id.m_id, utf8_to_wstr(templatePath).c_str(), utf8_to_wstr(layoutName).c_str(), pDb.impObj()));
    return id;
}

PyRxClass PyApLayoutManager::desc()
{
    return PyRxClass(AcApLayoutManager::desc(), false);
}

std::string PyApLayoutManager::className()
{
    return "AcApLayoutManager";
}

AcApLayoutManager* PyApLayoutManager::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcApLayoutManager*>(m_pyImp.get());
}
