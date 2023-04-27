#pragma once

//TODO:
//expose this as functions to python
//BeginEditorCommand();
//CancelEditorCommand();
//ComleteEditorCommand();



//-----------------------------------------------------------------------------------------
// WxUserInteraction
class WxUserInteraction
{
    HWND m_activeWindow;
    std::vector<HWND> m_wnds;
public:
    WxUserInteraction();
    WxUserInteraction(AcApDocument* pDocument, bool prompting);
    virtual ~WxUserInteraction(void);
protected:
    void userInteraction(AcApDocument* pDocument, bool prompting);
    void undoUserInteraction();
};

