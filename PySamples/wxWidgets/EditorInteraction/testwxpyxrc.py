import wx
from wx import xrc

from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

def OnPyInitApp():
    print("\nOnPyInitApp")
    print("Added command 'wxpyxrc'")

def OnPyUnloadApp():
    print("\nOnPyUnloadApp")

def OnPyLoadDwg():
    print("\nOnPyLoadDwg")

def OnPyUnloadDwg():
    print("\nOnPyUnloadDwg")
   
#command to launch the dialog
def PyRxCmd_wxpyxrc():
    try: 
        #CAcModuleResourceOverride
        resource = Ap.ResourceOverride()
        dlg = TestDialog(None, -1, "")
        if dlg.ShowModal() == wx.ID_OK:
            print('woohoo')
    except Exception as err:
        print(err)
    finally:
        # explicitly cause the dialog to destroy itself
        dlg.Destroy()

class TestDialog(wx.Dialog):
    def __init__(
            self, parent, id, title, size=wx.DefaultSize, pos=wx.DefaultPosition,
            style=wx.DEFAULT_DIALOG_STYLE, name='ID_SELECTTEST'):
        wx.Dialog.__init__(self)   
        self.res = xrc.XmlResource('./selectTest.xrc')
        if not self.res.LoadDialog(self, parent, "ID_SELECTTEST"):
            raise Exception("failed to find xrc file") 
        
        self.getPointButton = xrc.XRCCTRL(self,'ID_BUTTON_GET_POINT')
        self.Bind(wx.EVT_BUTTON, self.onGetPoint,self.getPointButton)
        
        self.getDistButton = xrc.XRCCTRL(self,'ID_BUTTON_GET_DIST')
        self.Bind(wx.EVT_BUTTON, self.onGetDist,self.getDistButton)

        self.textPointResult = xrc.XRCCTRL(self,'ID_TEXTCTRL_POINT_RESULT')
        self.textDistResult = xrc.XRCCTRL(self,'ID_TEXTCTRL_DIST_RESULT')
        
        Ap.Application.applyHostIcon(self.GetHandle())
      
    def onGetPoint(self, event):
        val = Ed.Editor().getPoint("\nGetPoint\n")
        if val[0] == Ed.PromptStatus.eNormal :
            self.textPointResult.SetValue(val[1].__str__())
            
    def onGetDist(self, event):
        val = Ap.Application().docManager().curDocument().editor().getDist("\nGetDist\n")
        if val[0] == Ed.PromptStatus.eNormal :
            self.textDistResult.SetValue(val[1].__str__())



