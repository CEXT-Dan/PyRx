#pragma once
#pragma pack (push, 8)
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
    void                    setPlotCancelStatus(AcPlPlotProgress::PlotCancelStatus Cancel) const;
    AcPlPlotProgress::PlotCancelStatus plotCancelStatus() const;
    void                    setPlotProgressRange(int nLower, int nUpper) const;
    boost::python::tuple    getPlotProgressRange() const;
    void                    setPlotProgressPos(int nPos) const;
    int                     plotProgressPos() const;
    bool                    isSheetCancelled() const;
    void                    setSheetCancelStatus(AcPlPlotProgress::SheetCancelStatus Cancel) const;
    AcPlPlotProgress::SheetCancelStatus sheetCancelStatus() const;
    void                    setSheetProgressRange(int nLower, int nUpper) const;
    boost::python::tuple    getSheetProgressRange() const;
    void                    setSheetProgressPos(int nPos) const;
    int                     sheetProgressPos() const;
    bool                    setIsVisible(bool bVisible) const;
    bool                    isVisible() const;
    bool                    setStatusMsgString(const std::string& pMsg) const;
    std::string             getStatusMsgString() const;
    void                    heartbeat(void) const;

    //----AcPlPlotProgressDialog section----
    bool                    onBeginPlot() const;
    bool                    onEndPlot() const;
    bool                    onBeginSheet() const;
    bool                    onEndSheet() const;
    bool                    setPlotMsgString(AcPlPlotProgressDialog::PlotMSGIndex index, const std::string& pMsg) const;
    std::string             getPlotMsgString(AcPlPlotProgressDialog::PlotMSGIndex index) const;
    bool                    isSingleSheetPlot() const;
    void                    destroy();
    static std::string      className();
public:
    AcPlPlotProgressDialog* impObj(const std::source_location& src = std::source_location::current()) const;
private:
    std::shared_ptr<AcPlPlotProgressDialog> m_impl = nullptr;
};

//AcPlPlotProgressDialog
#pragma pack (pop)
