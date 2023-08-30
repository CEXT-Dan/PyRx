#include "stdafx.h"
#include "PyPlPlotProgressDialog.h"

//-----------------------------------------------------------------------------------------
//PyPlPlotProgressDialog

void makePyPlPlotProgressDialogWrapper()
{

}

PyPlPlotProgressDialog::PyPlPlotProgressDialog()
    : m_impl(acplCreatePlotProgressDialog(adsw_acadMainWnd()))
{
}

PyPlPlotProgressDialog::PyPlPlotProgressDialog(bool bPreview, int nSheets, bool bShowCancelSheetButton)
    : m_impl(acplCreatePlotProgressDialog(adsw_acadMainWnd(), bPreview, nSheets, nullptr, bShowCancelSheetButton))
{
}

PyPlPlotProgressDialog::PyPlPlotProgressDialog(UINT_PTR hwnd, bool bPreview, int nSheets, bool bShowCancelSheetButton)
    : m_impl(acplCreatePlotProgressDialog((HWND)hwnd, bPreview, nSheets,nullptr, bShowCancelSheetButton))
{
}

PyPlPlotProgressDialog::~PyPlPlotProgressDialog()
{
    this->destroy();
}

void PyPlPlotProgressDialog::destroy()
{
    if (m_impl == nullptr)
    {
        m_impl->destroy();
        m_impl = nullptr;
    }
}

std::string PyPlPlotProgressDialog::className()
{
    return "AcPlPlotProgressDialog";
}

AcPlPlotProgressDialog* PyPlPlotProgressDialog::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_impl == nullptr) [[unlikely]]
        throw PyNullObject(src);
    return m_impl;
}
