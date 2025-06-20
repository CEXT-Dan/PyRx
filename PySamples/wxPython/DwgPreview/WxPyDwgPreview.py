import wx
from wx import xrc

from pyrx import Ap, Db, Ed

print("added command = wxpypr")


def PyRxCmd_wxpypr():
    try:
        _res = Ap.ResourceOverride()
        dlg = TestDialog(None, -1, "DWG Preview")
        if dlg.ShowModal() == wx.ID_OK:
            print("yay")
    except Exception as err:
        print(err)


class TestDialog(wx.Dialog):
    def __init__(
        self,
        parent,
        id,
        title,
        size=wx.DefaultSize,
        pos=wx.DefaultPosition,
        style=wx.DEFAULT_DIALOG_STYLE,
        name="dialog",
    ):

        wx.Dialog.__init__(self)
        self.res = xrc.XmlResource("./DwgPreview.xrc")
        if not self.res.LoadDialog(self, parent, "ID_DWGPREVIEW"):
            raise Exception("failed to find xrc file")

        self.m_dwgpath = ""
        self.m_hasOnShowPreviewEvent = False  # prevent reentry
        self.m_previewCtrl = xrc.XRCCTRL(self, "wxID_DWG_PREVIEW")
        self.m_buttonBrowse = xrc.XRCCTRL(self, "wxID_BUTTON_BROWSE")
        self.m_textCtrl = xrc.XRCCTRL(self, "wxID_TEXTCTRL")

        self.Bind(wx.EVT_BUTTON, self.OnBrowseButton, self.m_buttonBrowse)
        self.Bind(wx.EVT_INIT_DIALOG, self.OnInitDialog)
        self.Bind(wx.EVT_SIZE, self.OnSize)

    # make sure we only have one wx.EVT_IDLE
    def showPreview(self):
        if not self.m_hasOnShowPreviewEvent:
            self.m_previewCtrl.Bind(wx.EVT_IDLE, self.OnShowPreview)
            self.m_hasOnShowPreviewEvent = True

    # repaints the control, do dialog events, then update the preview
    def OnSize(self, event):
        event.Skip(True)
        self.showPreview()

    # get the preview on the next wx.EVT_IDLE
    # unbind the event to prevent loop
    def OnShowPreview(self, event):
        self.m_previewCtrl.Unbind(wx.EVT_IDLE)
        self.m_hasOnShowPreviewEvent = False
        if len(self.m_dwgpath) == 0:
            return
        Db.Core.displayPreviewFromDwg(self.m_dwgpath, self.m_previewCtrl.GetHandle())

    def OnInitDialog(self, event):
        Ap.Application.setTitleThemeDark(self.GetHandle())
        Ap.Application.applyHostIcon(self.GetHandle())

    def OnBrowseButton(self, event):
        self.m_dwgpath = Ed.Core.getFileD("*.dwg", "", "dwg", 32)
        self.m_textCtrl.SetValue(self.m_dwgpath)
        self.showPreview()
