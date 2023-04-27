import os
import wx

import win32api
import win32gui
import win32con

import PyRxApp# = all the global methods like acutPrintf,
import PyRx# = Runtime runtime
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services
import PyEd# = editor

def OnPyInitApp():
    PyRxApp.Printf("\nOnPyInitApp")

def OnPyUnloadApp():
   PyRxApp.Printf("\nOnPyUnloadApp")

def OnPyLoadDwg():
   PyRxApp.Printf("\nOnPyLoadDwg")

def OnPyUnloadDwg():
   PyRxApp.Printf("\nOnPyUnloadDwg")

WM_ACAD_KEEPFOCUS = 28929

#command to launch the dialog

def PyRxCmd_wxpy():
    try: 
        dlg = TestDialog(None, -1, "mY first diaLog",wx.Size(700,300))
        val = dlg.Show()
        if  val == wx.ID_OK:
            print(dlg.text1.GetValue())
            print(dlg.text2.GetValue())
    except Exception as err:
        PyRxApp.Printf(err)
    #finally:
        # explicitly cause the dialog to destroy itself
        #dlg.Destroy()
   
class TestDialog(wx.Dialog):
    def __init__(
            self, parent, id, title, size, pos=wx.DefaultPosition,
            style=wx.DEFAULT_DIALOG_STYLE, name='dialog'
            ):
    
        # Instead of calling wx.Dialog.__init__ we precreate the dialog
        # so we can set an extra style that must be set before
        # creation, and then we create the GUI object using the Create
        # method.
        wx.Dialog.__init__(self)
        self.SetExtraStyle(wx.DIALOG_EX_CONTEXTHELP)
        self.Create(parent, id, title, pos, size, style, name)
        
        # Now continue with the normal construction of the dialog
        # contents
        sizer = wx.BoxSizer(wx.VERTICAL)

        label = wx.StaticText(self, -1, "This is a wx.Dialog")
        sizer.Add(label, 0, wx.ALIGN_CENTRE|wx.ALL, 5)

        box = wx.BoxSizer(wx.HORIZONTAL)

        label = wx.StaticText(self, -1, "Field #1:")
        box.Add(label, 0, wx.ALIGN_CENTRE|wx.ALL, 5)

        self.text1 = wx.TextCtrl(self, -1, "", size=(200,-1))
        box.Add(self.text1, 1, wx.ALIGN_CENTRE|wx.ALL, 5)

        sizer.Add(box, 0, wx.EXPAND|wx.ALL, 5)

        box = wx.BoxSizer(wx.HORIZONTAL)

        label = wx.StaticText(self, -1, "Field #2:")
        box.Add(label, 0, wx.ALIGN_CENTRE|wx.ALL, 5)

        self.text2 = wx.TextCtrl(self, -1, "", size=(200,-1))
        box.Add(self.text2, 1, wx.ALIGN_CENTRE|wx.ALL, 5)

        sizer.Add(box, 0, wx.EXPAND|wx.ALL, 5)

        line = wx.StaticLine(self, -1, size=(20,-1), style=wx.LI_HORIZONTAL)
        sizer.Add(line, 0, wx.EXPAND|wx.RIGHT|wx.TOP, 5)

        btnsizer = wx.StdDialogButtonSizer()

        if wx.Platform != "__WXMSW__":
            btn = wx.ContextHelpButton(self)
            btnsizer.AddButton(btn)

        self.OK = wx.Button(self, wx.ID_OK)
        #Destroy might never happen, add event
        self.OK.Bind(wx.EVT_BUTTON, self.OnClose)
        self.OK.SetDefault()
        btnsizer.AddButton(self.OK)

        self.CANCEL = wx.Button(self, wx.ID_CANCEL)
        #Destroy might never happen, add event
        self.CANCEL.Bind(wx.EVT_BUTTON, self.OnClose)
        btnsizer.AddButton(self.CANCEL)
        btnsizer.Realize()
        
        sizer.Add(btnsizer, 0, wx.ALL, 5)

        self.SetSizer(sizer)
        sizer.Fit(self)
        
        #
        self.Bind(wx.EVT_CLOSE, self.OnClose)
        self.addHook()
    
    #we need this to capture WM_ACAD_KEEPFOCUS
    def addHook(self):
        self.oldWndProc = win32gui.SetWindowLong(self.GetHandle(),win32con.GWL_WNDPROC,self.MyWndProc)
        
    def restoreHook(self):
        wx.MessageBox("YAY")
        return win32api.SetWindowLong(self.GetHandle(), win32con.GWL_WNDPROC, self.oldWndProc) 
    
    def OnClose(self, event):
        self.restoreHook()
        self.Destroy()

    def MyWndProc(self, hWnd, msg, wParam, lParam):
        if msg == WM_ACAD_KEEPFOCUS:
            return 1
        elif msg == win32con.WM_DESTROY:
           self.restoreHook()
        return win32gui.CallWindowProc(self.oldWndProc,hWnd, msg, wParam, lParam)
    