import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

import wx
from wx import xrc


class MyPanel(wx.Panel):
    def __init__(self):
        super().__init__()
        self.Bind(wx.EVT_SHOW, self.OnShow)
        #self.Bind(wx.EVT_SIZE,self.OnSize)

    def OnShow(self, event):
        self.res = xrc.XmlResource('./wxPaletteTab.xrc')
        if not self.res.LoadPanel(self, "ID_WXPALETTETAB"):
             raise Exception("failed to find xrc file") 
         
        self.button1 = xrc.XRCCTRL(self,'wxID_BUTTON_1')
        self.Bind(wx.EVT_BUTTON, self.onButton1,self.button1)
        self.Layout()
        
    def OnSize(self,event):
        event.Skip(True)
        print(event.GetRect())
        
    def onButton1(self, event):
        print("button1")
        
    
        
        

palette = Ap.PaletteSet("MyPalette")

def createPalette():
    try:
        panel = MyPanel()
        palette.add("MyPanel", panel)
        palette.setOpacity(50)
        palette.setVisible(True)
        palette.setName("Didn't think this would work")
    except Exception as err:
        print(err)
        
def PyRxCmd_wxpy1():
    try:
        createPalette()
    except Exception as err:
        print(err)