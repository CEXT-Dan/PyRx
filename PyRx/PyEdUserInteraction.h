#pragma once

//TODO:
//expose this as functions to python
//BeginEditorCommand();
//CancelEditorCommand();
//ComleteEditorCommand();



//-----------------------------------------------------------------------------------------
// WxUserInteraction
class PyEdUserInteraction
{
    HWND m_activeWindow;
    std::vector<HWND> m_wnds;
public:
    PyEdUserInteraction();
    PyEdUserInteraction(AcApDocument* pDocument, bool prompting);
    virtual ~PyEdUserInteraction(void);
protected:
    void userInteraction(AcApDocument* pDocument, bool prompting);
    void undoUserInteraction();
};

