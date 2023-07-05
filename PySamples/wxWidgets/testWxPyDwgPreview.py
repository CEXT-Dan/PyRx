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
            style=wx.DEFAULT_DIALOG_STYLE, name='dialog'):

        wx.Dialog.__init__(self)
        self.SetExtraStyle(wx.DIALOG_EX_CONTEXTHELP)
        self.Create(parent, id, title, pos, size, style, name)
        self.Bind(wx.EVT_INIT_DIALOG, self.OnInitDialog)
        self.Bind(wx.EVT_IDLE,self.OnIdle)
        self.sbox = wx.StaticBox(self,-1,"Preview")
        self.sbox.SetSize(wx.Size(400, 200))
        
    def OnIdle(self,event):
        self.setPreview()
        
    def setPreview(self):
        PyDb.Core.displayPreviewFromDwg("E:\\Floor Plan Sample.dwg",  self.sbox.GetHandle())

    def OnInitDialog(self, event):
        PyAp.Application.setTitleThemeDark(self.GetHandle())
        PyAp.Application.applyHostIcon(self.GetHandle())


        
