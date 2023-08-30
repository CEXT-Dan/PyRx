#pragma once

struct PyPlPlotProgressDialogDeleter
{
    inline void operator()(AcPlPlotProgressDialog* p) const
    {
        if (p == nullptr) [[unlikely]]
            return;
        p->destroy();
    };
};

//-----------------------------------------------------------------------------------------
//PyPlPlotProgressDialog
void makePyPlPlotProgressDialogWrapper();

class PyPlPlotProgressDialog
{
public:
    PyPlPlotProgressDialog();
    PyPlPlotProgressDialog(bool bPreview, int nSheets, bool bShowCancelSheetButton);
    PyPlPlotProgressDialog(UINT_PTR hwnd, bool bPreview, int nSheets, bool bShowCancelSheetButton);
    ~PyPlPlotProgressDialog() = default;

    //----AcPlPlotProgress section----
    bool                    isPlotCancelled() const;
    void                    setPlotCancelStatus(AcPlPlotProgress::PlotCancelStatus Cancel);
    AcPlPlotProgress::PlotCancelStatus plotCancelStatus() const;

    void                    setPlotProgressRange(int nLower, int nUpper);
    boost::python::tuple    getPlotProgressRange();

    void                    setPlotProgressPos(int nPos);
    int                     plotProgressPos() const;

    bool                    isSheetCancelled() const;
    void                    setSheetCancelStatus(AcPlPlotProgress::SheetCancelStatus Cancel);
    AcPlPlotProgress::SheetCancelStatus sheetCancelStatus() const;

    void                    setSheetProgressRange(int nLower, int nUpper);
    boost::python::tuple    getSheetProgressRange() const;

    void                    setSheetProgressPos(int nPos);
    int                     sheetProgressPos() const;

    bool                    setIsVisible(bool bVisible);
    bool                    isVisible() const;

    bool                    setStatusMsgString(const std::string& pMsg);
    std::string             getStatusMsgString() const;

    void                    heartbeat(void);


    //----AcPlPlotProgressDialog section----
    bool                    onBeginPlot();
    bool                    onEndPlot();

    bool                    onBeginSheet();
    bool                    onEndSheet();

    bool                    setPlotMsgString(AcPlPlotProgressDialog::PlotMSGIndex index, const std::string& pMsg);
    std::string             getPlotMsgString(AcPlPlotProgressDialog::PlotMSGIndex index) const;

    bool                    isSingleSheetPlot() const;

    void                    destroy();

    static std::string      className();

public:
    inline AcPlPlotProgressDialog* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<AcPlPlotProgressDialog> m_impl = nullptr;
};

//AcPlPlotProgressDialog