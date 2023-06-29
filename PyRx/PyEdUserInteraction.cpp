#include "stdafx.h"
#include "PyEdUserInteraction.h"

//-----------------------------------------------------------------------------------------
// WxUserInteraction
PyEdUserInteraction::PyEdUserInteraction()
{
    userInteraction(acDocManagerPtr()->curDocument(), true);
}

PyEdUserInteraction::PyEdUserInteraction(AcApDocument* pDocument, bool prompting)
{
    userInteraction(pDocument, prompting);
}

PyEdUserInteraction::~PyEdUserInteraction(void)
{
    undoUserInteraction();
}

void PyEdUserInteraction::userInteraction(AcApDocument* pDocument, bool prompting)
{
    AcApDocManager* pDocMan = acDocManagerPtr();
    if (pDocMan->curDocument() == pDocument)
    {
        pDocMan->disableDocumentActivation();
        if (!prompting)
            return;

        HWND hwMainWnd = adsw_acadMainWnd();
        if (::IsWindowEnabled(hwMainWnd) == TRUE)
            return;

        m_activeWindow = GetFocus();
        for (HWND window = ::GetActiveWindow(); window != NULL; window = ::GetWindow(window, GW_OWNER))
        {
            if (window == hwMainWnd)
                break;
            m_wnds.push_back(window);
        }
        ::EnableWindow(hwMainWnd, TRUE);
        ::SetFocus(hwMainWnd);
        for (size_t idx = 0; idx < m_wnds.size(); idx++)
        {
            ::ShowWindow(m_wnds[idx], SW_HIDE);
        }
    }
}

void PyEdUserInteraction::undoUserInteraction()
{
    acDocManagerPtr()->enableDocumentActivation();
    if (m_wnds.size() > 0)
    {
        for (std::vector<HWND>::reverse_iterator it = m_wnds.rbegin(); it != m_wnds.rend(); ++it)
        {
            ::ShowWindow(*it, SW_SHOW);
        }
        ::EnableWindow(adsw_acadMainWnd(), FALSE);
        ::SetFocus(m_activeWindow);
    }
}


