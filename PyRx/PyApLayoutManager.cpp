#include "stdafx.h"
#include "PyApLayoutManager.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyApLayoutManagerWrapper()
{
    PyDocString DS("LayoutManager");
    class_<PyApLayoutManager, bases<PyDbLayoutManager>>("LayoutManager")
        .def("pageSetup", &PyApLayoutManager::pageSetup1)
        .def("pageSetup", &PyApLayoutManager::pageSetup2)
        .def("pageSetup", &PyApLayoutManager::pageSetup3, DS.CLASSARGS({ "layoutBTRId : PyDb.ObjectId=kNull","parent : int=kNull","isPageSetupDlg : bool=True" }))
        .def("updateCurrentPaper", &PyApLayoutManager::updateCurrentPaper1)
        .def("updateCurrentPaper", &PyApLayoutManager::updateCurrentPaper2, DS.CLASSARGS({ "zoomToPaper : bool=False" }))
        .def("updateLayoutTabs", &PyApLayoutManager::updateLayoutTabs, DS.CLASSARGS())
        .def("getActiveTab", &PyApLayoutManager::getActiveTab, DS.CLASSARGS())
        .def("showTabs", &PyApLayoutManager::showTabs, DS.CLASSARGS())
        .def("setShowTabs", &PyApLayoutManager::setShowTabs, DS.CLASSARGS({ "val : bool" }))
        .def("showPageSetup", &PyApLayoutManager::showPageSetup, DS.CLASSARGS())
        .def("setShowPageSetup", &PyApLayoutManager::setShowPageSetup, DS.CLASSARGS({ "val : bool" }))
        .def("createViewports", &PyApLayoutManager::createViewports, DS.CLASSARGS())
        .def("setCreateViewports", &PyApLayoutManager::setCreateViewports, DS.CLASSARGS({ "val : bool" }))
        .def("showPaperBackground", &PyApLayoutManager::showPaperBackground, DS.CLASSARGS())
        .def("setShowPaperBackground", &PyApLayoutManager::setShowPaperBackground, DS.CLASSARGS({ "val : bool" }))
        .def("showPaperMargins", &PyApLayoutManager::showPaperMargins, DS.CLASSARGS())
        .def("setShowPaperMargins", &PyApLayoutManager::setShowPaperMargins, DS.CLASSARGS({ "val : bool" }))
        .def("showPrintBorder", &PyApLayoutManager::showPrintBorder, DS.CLASSARGS())
        .def("setShowPrintBorder", &PyApLayoutManager::setShowPrintBorder, DS.CLASSARGS({ "val : bool" }))
        .def("generateNextNewLayoutName", &PyApLayoutManager::generateNextNewLayoutName1)
        .def("generateNextNewLayoutName", &PyApLayoutManager::generateNextNewLayoutName2, DS.CLASSARGS({ "val : PyDb.Database=current" }))
        .def("setDefaultPlotConfig", &PyApLayoutManager::setDefaultPlotConfig, DS.CLASSARGS({ "val : PyDb.ObjectId" }))
        .def("getClipBoundaryElabration", &PyApLayoutManager::getClipBoundaryElabration, DS.CLASSARGS({ "val : PyDb.ObjectId" }))
        .def("pointInViewports", &PyApLayoutManager::pointInViewports, DS.CLASSARGS({ "val : PyGe.Point3d" }))
        .def("setCaptureOnLayoutSwitch", &PyApLayoutManager::setCaptureOnLayoutSwitch, DS.CLASSARGS({ "val : bool" }))
        .def("createLayoutFromTemplate", &PyApLayoutManager::createLayoutFromTemplate1)
        .def("createLayoutFromTemplate", &PyApLayoutManager::createLayoutFromTemplate2, DS.CLASSARGS({ "newLayoutName : str","templatePath : str","layoutName : str","db : PyDb.Database=current" }))
        .def("desc", &PyApLayoutManager::desc, DS.CLASSARGSSTATIC()).staticmethod("desc")
        .def("className", &PyApLayoutManager::className, DS.CLASSARGSSTATIC()).staticmethod("className")
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

int PyApLayoutManager::pageSetup1()
{
    return impObj()->pageSetup();
}

int PyApLayoutManager::pageSetup2(const PyDbObjectId& lid)
{
    return impObj()->pageSetup(lid.m_id);
}

int PyApLayoutManager::pageSetup3(const PyDbObjectId& lid, UINT_PTR wnd, Adesk::Boolean isPageSetupDlg)
{
    return impObj()->pageSetup(lid.m_id, (void*)wnd, isPageSetupDlg);
}

void PyApLayoutManager::updateCurrentPaper1()
{
    return impObj()->updateCurrentPaper();
}

void PyApLayoutManager::updateCurrentPaper2(Adesk::Boolean zoomToPaper)
{
    return impObj()->updateCurrentPaper(zoomToPaper);
}

void PyApLayoutManager::updateLayoutTabs()
{
    return impObj()->updateLayoutTabs();
}

std::string PyApLayoutManager::getActiveTab()
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    AcString sName;
    PyThrowBadEs(impObj()->getActiveTab(sName));
    return wstr_to_utf8(sName);
#endif
}

Adesk::Boolean PyApLayoutManager::showTabs()
{
    return impObj()->showTabs();
}

void PyApLayoutManager::setShowTabs(Adesk::Boolean showTabs)
{
    return impObj()->setShowTabs(showTabs);
}

Adesk::Boolean PyApLayoutManager::showPageSetup()
{
    return impObj()->showPageSetup();
}

void PyApLayoutManager::setShowPageSetup(Adesk::Boolean showPageSetupDlg)
{
    return impObj()->setShowPageSetup(showPageSetupDlg);
}

Adesk::Boolean PyApLayoutManager::createViewports()
{
    return impObj()->createViewports();
}

void PyApLayoutManager::setCreateViewports(Adesk::Boolean createViewports)
{
    return impObj()->setCreateViewports(createViewports);
}

Adesk::Boolean PyApLayoutManager::showPaperBackground()
{
    return impObj()->showPaperBackground();
}

void PyApLayoutManager::setShowPaperBackground(Adesk::Boolean showPaperBackground)
{
    return impObj()->setShowPaperBackground(showPaperBackground);
}

Adesk::Boolean PyApLayoutManager::showPaperMargins()
{
    return impObj()->showPaperMargins();
}

void PyApLayoutManager::setShowPaperMargins(Adesk::Boolean showPaperMargins)
{
    return impObj()->setShowPaperMargins(showPaperMargins);
}

Adesk::Boolean PyApLayoutManager::showPrintBorder()
{
    return impObj()->showPrintBorder();
}

void PyApLayoutManager::setShowPrintBorder(Adesk::Boolean showPrintBorder)
{
    return impObj()->setShowPrintBorder(showPrintBorder);
}

std::string PyApLayoutManager::generateNextNewLayoutName1()
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    AcString sName;
    PyThrowBadEs(impObj()->generateNextNewLayoutName(sName));
    return wstr_to_utf8(sName);
#endif
}

std::string PyApLayoutManager::generateNextNewLayoutName2(PyDbDatabase& useDb)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    AcString sName;
    PyThrowBadEs(impObj()->generateNextNewLayoutName(sName, useDb.impObj()));
    return wstr_to_utf8(sName);
#endif
}

void PyApLayoutManager::setDefaultPlotConfig(PyDbObjectId& layoutBTRId)
{
    return impObj()->setDefaultPlotConfig(layoutBTRId.m_id);
}

boost::python::list PyApLayoutManager::getClipBoundaryElabration(const PyDbObjectId& clipId)
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    AcGePoint2dArray* clipBoundary = nullptr;
    PyThrowBadEs(impObj()->getClipBoundaryElaboration(clipId.m_id, clipBoundary));
    if (clipBoundary != nullptr)
    {
        for (auto& item : *clipBoundary)
            pyList.append(item);
    }
    return pyList;
}

boost::python::list PyApLayoutManager::pointInViewports(const AcGePoint3d& pickPt)
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    AcDbObjectIdArray viewports;
    PyThrowBadEs(impObj()->pointInViewports(pickPt, viewports));
    for (auto& item : viewports)
        pyList.append(item);
    return pyList;
}

void PyApLayoutManager::setCaptureOnLayoutSwitch(bool bCaptureOnLayout)
{
    return impObj()->setCaptureOnLayoutSwitch(bCaptureOnLayout);
}

PyDbObjectId PyApLayoutManager::createLayoutFromTemplate1(const std::string& newLayoutName, const std::string& templatePath, const std::string& layoutName)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    PyDbObjectId id;
    PyThrowBadEs(impObj()->createLayoutFromTemplate(utf8_to_wstr(newLayoutName).c_str(), id.m_id, utf8_to_wstr(templatePath).c_str(), utf8_to_wstr(layoutName).c_str()));
    return id;
#endif
}

PyDbObjectId PyApLayoutManager::createLayoutFromTemplate2(const std::string& newLayoutName, const std::string& templatePath, const std::string& layoutName, PyDbDatabase& pDb)
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    throw PyNotimplementedByHost();
#else
    PyDbObjectId id;
    PyThrowBadEs(impObj()->createLayoutFromTemplate(utf8_to_wstr(newLayoutName).c_str(), id.m_id, utf8_to_wstr(templatePath).c_str(), utf8_to_wstr(layoutName).c_str(), pDb.impObj()));
    return id;
#endif
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
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcApLayoutManager*>(m_pyImp.get());
}
