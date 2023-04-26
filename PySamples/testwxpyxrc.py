import wx
from wx import xrc

import PyRxApp# = all the global methods like acutPrintf,
import PyRx# = Runtime runtime
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services
import PyEd# = editor

def OnPyInitApp():
    print("\nOnPyInitApp")

def OnPyUnloadApp():
    print("\nOnPyUnloadApp")

def OnPyLoadDwg():
    print("\nOnPyLoadDwg")

def OnPyUnloadDwg():
   print("\nOnPyUnloadDwg")

#command to launch the dialog
def PyRxCmd_wxpyxrc():
    try: 
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
            style=wx.DEFAULT_DIALOG_STYLE, name='DlgTable'):
        wx.Dialog.__init__(self)   
        self.res = xrc.XmlResource('C:/Users/Dan/Documents/DialogBlocks Projects/table dlg/wxg_dlg_inserttable.xrc')
        self.res.LoadDialog(self, parent, "DLG_INSERTTABLE")


