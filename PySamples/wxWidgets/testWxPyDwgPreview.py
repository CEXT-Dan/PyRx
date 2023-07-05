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
        self.Create(parent, id, title, pos, size, style, name)
        self.Bind(wx.EVT_INIT_DIALOG, self.OnInitDialog)

        self.sbox = wx.StaticBox(self,-1,"Preview")
        self.sbox.SetSize(wx.Size(400, 200))  
        self.timer = wx.Timer(self)
        self.Bind(wx.EVT_TIMER, self.OnTimer, self.timer)
       
    def OnTimer(self, event):
        self.timer.Stop()
        self.setPreview()
        
    def setPreview(self):
        PyDb.Core.displayPreviewFromDwg("E:\\Floor Plan Sample.dwg",  self.sbox.GetHandle())

    def OnInitDialog(self, event):
        PyAp.Application.setTitleThemeDark(self.GetHandle())
        PyAp.Application.applyHostIcon(self.GetHandle())
        self.timer.Start(10)




        
