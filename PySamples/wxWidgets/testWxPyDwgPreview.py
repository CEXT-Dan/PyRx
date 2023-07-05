import PyRx
import PyGe
import PyGi
import PyDb
import PyAp
import PyEd
import wx

print("added command = wxpypr")

def PyRxCmd_wxpypr():
    try:
        res = PyAp.ResourceOverride()
        dlg = TestDialog(None, -1, "DWG Preview", wx.Size(450, 250))
        if dlg.ShowModal() == wx.ID_OK:
            print("yay")
    except Exception as err:
        print(err)

class TestDialog(wx.Dialog):
    def __init__(
            self, parent, id, title, size, pos=wx.DefaultPosition,
            style=wx.DEFAULT_DIALOG_STYLE | wx.FULL_REPAINT_ON_RESIZE, name='dialog'):

        wx.Dialog.__init__(self)
        self.Create(parent, id, title, pos, size, style, name)
        self.Bind(wx.EVT_INIT_DIALOG, self.OnInitDialog)
        self.previewBox = wx.StaticBox(self, -1, "Preview")
        self.previewBox.SetSize(wx.Size(400, 200))

    def setPreview(self, path):
        self.dwgPath = path
        self.previewBox.Bind(wx.EVT_IDLE, self.OnShowPreview)

    def OnShowPreview(self, event):
        PyDb.Core.displayPreviewFromDwg(self.dwgPath, self.previewBox.GetHandle())
        self.previewBox.Unbind(wx.EVT_IDLE)

    def OnInitDialog(self, event):
        PyAp.Application.setTitleThemeDark(self.GetHandle())
        PyAp.Application.applyHostIcon(self.GetHandle())
        self.setPreview("E:\\Floor Plan Sample.dwg")
