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
        
    def OnShow(self, event):
        
        #import the XRC
        wx.ToolTip.Enable(True)
        self.res = xrc.XmlResource('./wxPaletteTab.xrc')
        self.childpanel = self.res.LoadPanel(self, "ID_WXPALETTETAB")
        if not self.childpanel:
             raise Exception("failed to find xrc file") 
        
        #create a sizer and add the child
        sizer = wx.BoxSizer(wx.VERTICAL)
        sizer.Add(self.childpanel,1,wx.ALL|wx.EXPAND)
        self.SetSizer(sizer)
        self.Layout()

        #get ctrls as member variables 
        self.comboctrl = xrc.XRCCTRL(self,'wxID_COMBOCTRL')
        self.textctrl = xrc.XRCCTRL(self,'wxID_TEXTCTRL')
        self.radioleftctrl = xrc.XRCCTRL(self,'wxID_RADIOBUTTON_LEFT')
        self.radiorightctrl = xrc.XRCCTRL(self,'wxID_RADIOBUTTON_RIGHT')
        self.button_1ctrl = xrc.XRCCTRL(self,'wxID_BUTTON_1')
        self.button_2ctrl = xrc.XRCCTRL(self,'wxID_BUTTON_2')
        self.listctrl = xrc.XRCCTRL(self,'wxID_LISTCTRL')
        
        #bind events
        self.Bind(wx.EVT_CHOICE,self.OnChoice,self.comboctrl)
        self.Bind(wx.EVT_CHAR_HOOK,self.OnEventChar, self.textctrl)
        
    def OnChoice(self, event):
        selection = self.comboctrl.GetSelection()
        selectionString = self.comboctrl.GetString(selection)
        print(selection,selectionString)
        
    def OnEventChar(self, event):
        keyCode = event.GetKeyCode() 
        character = chr(keyCode)
        print(keyCode,character)
        event.Skip()
        
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
        
def PyRxCmd_wxdoit():
    try:
        createPalette()
    except Exception as err:
        print(err)