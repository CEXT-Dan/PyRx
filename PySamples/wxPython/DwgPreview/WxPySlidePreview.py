import wx
from wx import xrc

from pyrx import Ap, Db, Ed, Gs

print("added command = wxsld")

@Ap.Command()
def wxsld():
    try:
        _res = Ap.ResourceOverride()
        dlg = TestDialog(None, -1, "Slide Preview")
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

        self.SetTitle("Slide Preview")
        self.m_dwgpath = ""
        self.m_previewCtrl = xrc.XRCCTRL(self, "wxID_DWG_PREVIEW")
        self.m_buttonBrowse = xrc.XRCCTRL(self, "wxID_BUTTON_BROWSE")
        self.m_textCtrl = xrc.XRCCTRL(self, "wxID_TEXTCTRL")

        self.Bind(wx.EVT_BUTTON, self.OnBrowseButton, self.m_buttonBrowse)
        self.Bind(wx.EVT_INIT_DIALOG, self.OnInitDialog)
        self.Bind(wx.EVT_SIZE, self.OnSize)

    def showPreview(self):
        sz =  self.m_previewCtrl.GetSize()
        image : wx.Image = Gs.Core.slideToWxImage(self.m_dwgpath, sz.width, sz.height, [49,56,66])
        self.m_previewCtrl.SetBitmap(image.ConvertToBitmap())


    def OnSize(self, event):
        event.Skip(True)
        self.showPreview()

    def OnInitDialog(self, event):
        Ap.Application.setTitleThemeDark(self.GetHandle())
        Ap.Application.applyHostIcon(self.GetHandle())

    def OnBrowseButton(self, event):
        self.m_dwgpath = Ed.Core.getFileD("*.sld", "", "sld", 32)
        self.m_textCtrl.SetValue(self.m_dwgpath)
        self.showPreview()
