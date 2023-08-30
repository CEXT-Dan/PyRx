#include "stdafx.h"
#include "PyPlPlotProgressDialog.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyPlPlotProgressDialog
void makePyPlPlotProgressDialogWrapper()
{
    PyDocString DS("PlotProgressDialog");
    class_<PyPlPlotProgressDialog>("PlotProgressDialog")
        .def(init<>())
        .def(init<bool, int, bool>())
        .def(init<UINT_PTR, bool, int, bool>())
        .def("isPlotCancelled", &PyPlPlotProgressDialog::isPlotCancelled)
        .def("setPlotCancelStatus", &PyPlPlotProgressDialog::setPlotCancelStatus)
        .def("plotCancelStatus", &PyPlPlotProgressDialog::plotCancelStatus)
        .def("setPlotProgressRange", &PyPlPlotProgressDialog::setPlotProgressRange)
        .def("getPlotProgressRange", &PyPlPlotProgressDialog::getPlotProgressRange)
        .def("setPlotProgressPos", &PyPlPlotProgressDialog::setPlotProgressPos)
        .def("plotProgressPos", &PyPlPlotProgressDialog::plotProgressPos)
        .def("isSheetCancelled", &PyPlPlotProgressDialog::isSheetCancelled)
        .def("setSheetCancelStatus", &PyPlPlotProgressDialog::setSheetCancelStatus)
        .def("sheetCancelStatus", &PyPlPlotProgressDialog::sheetCancelStatus)
        .def("setSheetProgressRange", &PyPlPlotProgressDialog::setSheetProgressRange)
        .def("getSheetProgressRange", &PyPlPlotProgressDialog::getSheetProgressRange)
        .def("setSheetProgressPos", &PyPlPlotProgressDialog::setSheetProgressPos)
        .def("sheetProgressPos", &PyPlPlotProgressDialog::sheetProgressPos)
        .def("setIsVisible", &PyPlPlotProgressDialog::setIsVisible)
        .def("isVisible", &PyPlPlotProgressDialog::isVisible)
        .def("setStatusMsgString", &PyPlPlotProgressDialog::setStatusMsgString)
        .def("getStatusMsgString", &PyPlPlotProgressDialog::getStatusMsgString)
        .def("heartbeat", &PyPlPlotProgressDialog::heartbeat)
        .def("onBeginPlot", &PyPlPlotProgressDialog::onBeginPlot)
        .def("onEndPlot", &PyPlPlotProgressDialog::onEndPlot)
        .def("onBeginSheet", &PyPlPlotProgressDialog::onBeginSheet)
        .def("onEndSheet", &PyPlPlotProgressDialog::onEndSheet)
        .def("setPlotMsgString", &PyPlPlotProgressDialog::setPlotMsgString)
        .def("getPlotMsgString", &PyPlPlotProgressDialog::getPlotMsgString)
        .def("isSingleSheetPlot", &PyPlPlotProgressDialog::isSingleSheetPlot)
        .def("destroy", &PyPlPlotProgressDialog::destroy)
        .def("className", &PyPlPlotProgressDialog::className, DS.SARGS()).staticmethod("className")
        ;

    enum_<AcPlPlotProgressDialog::PlotMSGIndex>("PlotMSGIndex")
        .value("kDialogTitle", AcPlPlotProgressDialog::PlotMSGIndex::kDialogTitle)
        .value("kSheetName", AcPlPlotProgressDialog::PlotMSGIndex::kSheetName)
        .value("kSheetNameToolTip", AcPlPlotProgressDialog::PlotMSGIndex::kSheetNameToolTip)
        .value("kStatus", AcPlPlotProgressDialog::PlotMSGIndex::kStatus)
        .value("kSheetProgressCaption", AcPlPlotProgressDialog::PlotMSGIndex::kSheetProgressCaption)
        .value("kSheetSetProgressCaption", AcPlPlotProgressDialog::PlotMSGIndex::kSheetSetProgressCaption)
        .value("kMsgCancelling", AcPlPlotProgressDialog::PlotMSGIndex::kMsgCancelling)
        .value("kMsgCancellingCurrent", AcPlPlotProgressDialog::PlotMSGIndex::kMsgCancellingCurrent)
        .value("kCancelSheetBtnMsg", AcPlPlotProgressDialog::PlotMSGIndex::kCancelSheetBtnMsg)
        .value("kCancelJobBtnMsg", AcPlPlotProgressDialog::PlotMSGIndex::kCancelJobBtnMsg)
        .value("kMsgCount", AcPlPlotProgressDialog::PlotMSGIndex::kMsgCount)
        .export_values()
        ;

    enum_<AcPlPlotProgress::SheetCancelStatus>("SheetCancelStatus")
        .value("kSheetContinue", AcPlPlotProgress::SheetCancelStatus::kSheetContinue)
        .value("kSheetCanceledByCancelButton", AcPlPlotProgress::SheetCancelStatus::kSheetCanceledByCancelButton)
        .value("kSheetCanceledByCancelAllButton", AcPlPlotProgress::SheetCancelStatus::kSheetCanceledByCancelAllButton)
        .value("kSheetCanceledByCaller", AcPlPlotProgress::SheetCancelStatus::kSheetCanceledByCaller)
        .value("kSheetCancelStatusCount", AcPlPlotProgress::SheetCancelStatus::kSheetCancelStatusCount)
        .export_values()
        ;

    enum_<AcPlPlotProgress::PlotCancelStatus>("PlotCancelStatus")
        .value("kPlotContinue", AcPlPlotProgress::PlotCancelStatus::kPlotContinue)
        .value("kPlotCanceledByCaller", AcPlPlotProgress::PlotCancelStatus::kPlotCanceledByCaller)
        .value("kPlotCanceledByCancelAllButton", AcPlPlotProgress::PlotCancelStatus::kPlotCanceledByCancelAllButton)
        .value("kPlotCancelStatusCount", AcPlPlotProgress::PlotCancelStatus::kPlotCancelStatusCount)
        .export_values()
        ;
}

struct PyPlPlotProgressDialogDeleter
{
    inline void operator()(AcPlPlotProgressDialog* p) const
    {
        if (p == nullptr) [[unlikely]]
            return;
        p->destroy();
    };
};

PyPlPlotProgressDialog::PyPlPlotProgressDialog()
    : m_impl(acplCreatePlotProgressDialog(adsw_acadMainWnd()), PyPlPlotProgressDialogDeleter())
{
}

PyPlPlotProgressDialog::PyPlPlotProgressDialog(bool bPreview, int nSheets, bool bShowCancelSheetButton)
    : m_impl(acplCreatePlotProgressDialog(adsw_acadMainWnd(), bPreview, nSheets, nullptr, bShowCancelSheetButton), PyPlPlotProgressDialogDeleter())
{
}

PyPlPlotProgressDialog::PyPlPlotProgressDialog(UINT_PTR hwnd, bool bPreview, int nSheets, bool bShowCancelSheetButton)
    : m_impl(acplCreatePlotProgressDialog((HWND)hwnd, bPreview, nSheets, nullptr, bShowCancelSheetButton), PyPlPlotProgressDialogDeleter())
{
}

bool PyPlPlotProgressDialog::isPlotCancelled() const
{
    return impObj()->isPlotCancelled();
}

void PyPlPlotProgressDialog::setPlotCancelStatus(AcPlPlotProgress::PlotCancelStatus Cancel)
{
    impObj()->setPlotCancelStatus(Cancel);
}

AcPlPlotProgress::PlotCancelStatus PyPlPlotProgressDialog::plotCancelStatus() const
{
    return impObj()->plotCancelStatus();
}

void PyPlPlotProgressDialog::setPlotProgressRange(int nLower, int nUpper)
{
    impObj()->setPlotProgressRange(nLower, nUpper);
}

boost::python::tuple PyPlPlotProgressDialog::getPlotProgressRange()
{
    PyAutoLockGIL lock;
    int nLower = 0;
    int nUpper = 0;
    impObj()->getPlotProgressRange(nLower, nUpper);
    return boost::python::make_tuple(nLower, nUpper);
}

void PyPlPlotProgressDialog::setPlotProgressPos(int nPos)
{
    impObj()->setPlotProgressPos(nPos);
}

int PyPlPlotProgressDialog::plotProgressPos() const
{
    return impObj()->plotProgressPos();
}

bool PyPlPlotProgressDialog::isSheetCancelled() const
{
    return impObj()->isSheetCancelled();
}

void PyPlPlotProgressDialog::setSheetCancelStatus(AcPlPlotProgress::SheetCancelStatus Cancel)
{
    impObj()->setSheetCancelStatus(Cancel);
}

AcPlPlotProgress::SheetCancelStatus PyPlPlotProgressDialog::sheetCancelStatus() const
{
    return impObj()->sheetCancelStatus();
}

void PyPlPlotProgressDialog::setSheetProgressRange(int nLower, int nUpper)
{
    impObj()->setSheetProgressRange(nLower, nUpper);
}

boost::python::tuple PyPlPlotProgressDialog::getSheetProgressRange() const
{
    PyAutoLockGIL lock;
    int nLower = 0;
    int nUpper = 0;
    impObj()->getSheetProgressRange(nLower, nUpper);
    return boost::python::make_tuple(nLower, nUpper);
}

void PyPlPlotProgressDialog::setSheetProgressPos(int nPos)
{
    impObj()->setSheetProgressPos(nPos);
}

int PyPlPlotProgressDialog::sheetProgressPos() const
{
    return impObj()->sheetProgressPos();
}

bool PyPlPlotProgressDialog::setIsVisible(bool bVisible)
{
    return impObj()->setIsVisible(bVisible);
}

bool PyPlPlotProgressDialog::isVisible() const
{
    return impObj()->isVisible();
}

bool PyPlPlotProgressDialog::setStatusMsgString(const std::string& pMsg)
{
    return impObj()->setStatusMsgString(utf8_to_wstr(pMsg).c_str());
}

std::string PyPlPlotProgressDialog::getStatusMsgString() const
{
    RxAutoOutStr str;
    impObj()->getStatusMsgString(str.buf);
    return wstr_to_utf8(str.buf);
}

void PyPlPlotProgressDialog::heartbeat(void)
{
    impObj()->heartbeat();
}

bool PyPlPlotProgressDialog::onBeginPlot()
{
    return impObj()->onBeginPlot();
}

bool PyPlPlotProgressDialog::onEndPlot()
{
    return impObj()->onEndPlot();
}

bool PyPlPlotProgressDialog::onBeginSheet()
{
    return impObj()->onBeginSheet();
}

bool PyPlPlotProgressDialog::onEndSheet()
{
    return impObj()->onEndSheet();
}

bool PyPlPlotProgressDialog::setPlotMsgString(AcPlPlotProgressDialog::PlotMSGIndex index, const std::string& pMsg)
{
    return impObj()->setPlotMsgString(index, utf8_to_wstr(pMsg).c_str());
}

std::string PyPlPlotProgressDialog::getPlotMsgString(AcPlPlotProgressDialog::PlotMSGIndex index) const
{
    RxAutoOutStr str;
    impObj()->getPlotMsgString(index, str.buf);
    return wstr_to_utf8(str.buf);
}

bool PyPlPlotProgressDialog::isSingleSheetPlot() const
{
    return impObj()->isSingleSheetPlot();
}

void PyPlPlotProgressDialog::destroy()
{
    m_impl.reset();
}

std::string PyPlPlotProgressDialog::className()
{
    return "AcPlPlotProgressDialog";
}

AcPlPlotProgressDialog* PyPlPlotProgressDialog::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_impl == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return m_impl.get();
}
