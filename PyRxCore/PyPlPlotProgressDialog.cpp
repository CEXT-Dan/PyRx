#include "stdafx.h"
#include "PyPlPlotProgressDialog.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyPlPlotProgressDialog
void makePyPlPlotProgressDialogWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- bPreview:bool, nSheets:int, bShowCancelSheetButton:bool\n"
        "- hwnd:int, bPreview:bool, nSheets:int, bShowCancelSheetButton:bool\n";

    PyDocString DS("PlotProgressDialog");
    class_<PyPlPlotProgressDialog>("PlotProgressDialog")
        .def(init<>())
        .def(init<bool, int, bool>())
        .def(init<UINT_PTR, bool, int, bool>(DS.CTOR(ctor)))
        .def("isPlotCancelled", &PyPlPlotProgressDialog::isPlotCancelled, DS.ARGS())
        .def("setPlotCancelStatus", &PyPlPlotProgressDialog::setPlotCancelStatus, DS.ARGS({ "val:PyPl.PlotCancelStatus" }))
        .def("plotCancelStatus", &PyPlPlotProgressDialog::plotCancelStatus, DS.ARGS())
        .def("setPlotProgressRange", &PyPlPlotProgressDialog::setPlotProgressRange, DS.ARGS({ "lower: int" , "upper: int" }))
        .def("getPlotProgressRange", &PyPlPlotProgressDialog::getPlotProgressRange, DS.ARGS())
        .def("setPlotProgressPos", &PyPlPlotProgressDialog::setPlotProgressPos, DS.ARGS({ "pos: int" }))
        .def("plotProgressPos", &PyPlPlotProgressDialog::plotProgressPos, DS.ARGS())
        .def("isSheetCancelled", &PyPlPlotProgressDialog::isSheetCancelled, DS.ARGS())
        .def("setSheetCancelStatus", &PyPlPlotProgressDialog::setSheetCancelStatus, DS.ARGS({ "val:PyPl.SheetCancelStatus" }))
        .def("sheetCancelStatus", &PyPlPlotProgressDialog::sheetCancelStatus, DS.ARGS())
        .def("setSheetProgressRange", &PyPlPlotProgressDialog::setSheetProgressRange, DS.ARGS({ "lower: int" , "upper: int" }))
        .def("getSheetProgressRange", &PyPlPlotProgressDialog::getSheetProgressRange, DS.ARGS())
        .def("setSheetProgressPos", &PyPlPlotProgressDialog::setSheetProgressPos, DS.ARGS({ "pos: int" }))
        .def("sheetProgressPos", &PyPlPlotProgressDialog::sheetProgressPos, DS.ARGS())
        .def("setIsVisible", &PyPlPlotProgressDialog::setIsVisible, DS.ARGS({ "val: bool" }))
        .def("isVisible", &PyPlPlotProgressDialog::isVisible, DS.ARGS())
        .def("setStatusMsgString", &PyPlPlotProgressDialog::setStatusMsgString, DS.ARGS({ "val: str" }))
        .def("getStatusMsgString", &PyPlPlotProgressDialog::getStatusMsgString, DS.ARGS())
        .def("heartbeat", &PyPlPlotProgressDialog::heartbeat, DS.ARGS())
        .def("onBeginPlot", &PyPlPlotProgressDialog::onBeginPlot, DS.ARGS())
        .def("onEndPlot", &PyPlPlotProgressDialog::onEndPlot, DS.ARGS())
        .def("onBeginSheet", &PyPlPlotProgressDialog::onBeginSheet, DS.ARGS())
        .def("onEndSheet", &PyPlPlotProgressDialog::onEndSheet, DS.ARGS())
        .def("setPlotMsgString", &PyPlPlotProgressDialog::setPlotMsgString, DS.ARGS({ "index:PyPl.PlotMSGIndex", "val: str" }))
        .def("getPlotMsgString", &PyPlPlotProgressDialog::getPlotMsgString, DS.ARGS({ "index:PyPl.PlotMSGIndex" }))
        .def("isSingleSheetPlot", &PyPlPlotProgressDialog::isSingleSheetPlot, DS.ARGS())
        .def("destroy", &PyPlPlotProgressDialog::destroy, DS.ARGS())
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

void PyPlPlotProgressDialog::setPlotCancelStatus(AcPlPlotProgress::PlotCancelStatus Cancel) const
{
    impObj()->setPlotCancelStatus(Cancel);
}

AcPlPlotProgress::PlotCancelStatus PyPlPlotProgressDialog::plotCancelStatus() const
{
    return impObj()->plotCancelStatus();
}

void PyPlPlotProgressDialog::setPlotProgressRange(int nLower, int nUpper) const
{
    impObj()->setPlotProgressRange(nLower, nUpper);
}

boost::python::tuple PyPlPlotProgressDialog::getPlotProgressRange() const
{
    PyAutoLockGIL lock;
    int nLower = 0;
    int nUpper = 0;
    impObj()->getPlotProgressRange(nLower, nUpper);
    return boost::python::make_tuple(nLower, nUpper);
}

void PyPlPlotProgressDialog::setPlotProgressPos(int nPos) const
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

void PyPlPlotProgressDialog::setSheetCancelStatus(AcPlPlotProgress::SheetCancelStatus Cancel) const
{
    impObj()->setSheetCancelStatus(Cancel);
}

AcPlPlotProgress::SheetCancelStatus PyPlPlotProgressDialog::sheetCancelStatus() const
{
    return impObj()->sheetCancelStatus();
}

void PyPlPlotProgressDialog::setSheetProgressRange(int nLower, int nUpper) const
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

void PyPlPlotProgressDialog::setSheetProgressPos(int nPos) const
{
    impObj()->setSheetProgressPos(nPos);
}

int PyPlPlotProgressDialog::sheetProgressPos() const
{
    return impObj()->sheetProgressPos();
}

bool PyPlPlotProgressDialog::setIsVisible(bool bVisible) const
{
    return impObj()->setIsVisible(bVisible);
}

bool PyPlPlotProgressDialog::isVisible() const
{
    return impObj()->isVisible();
}

bool PyPlPlotProgressDialog::setStatusMsgString(const std::string& pMsg) const
{
    return impObj()->setStatusMsgString(utf8_to_wstr(pMsg).c_str());
}

std::string PyPlPlotProgressDialog::getStatusMsgString() const
{
    RxAutoOutStr str;
    impObj()->getStatusMsgString(str.buf);
    return wstr_to_utf8(str.buf);
}

void PyPlPlotProgressDialog::heartbeat(void) const
{
    impObj()->heartbeat();
}

bool PyPlPlotProgressDialog::onBeginPlot() const
{
    return impObj()->onBeginPlot();
}

bool PyPlPlotProgressDialog::onEndPlot() const
{
    return impObj()->onEndPlot();
}

bool PyPlPlotProgressDialog::onBeginSheet() const
{
    return impObj()->onBeginSheet();
}

bool PyPlPlotProgressDialog::onEndSheet() const
{
    return impObj()->onEndSheet();
}

bool PyPlPlotProgressDialog::setPlotMsgString(AcPlPlotProgressDialog::PlotMSGIndex index, const std::string& pMsg) const
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
    if (m_impl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_impl.get();
}
