import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

import wx
from wx import xrc
from datetime import date

class PopMenu(wx.Menu):
    def __init__(self, parent):
        res = Ap.ResourceOverride()
        super(PopMenu, self).__init__()
        self.parent = parent
        popmenu = wx.MenuItem(self, 10001, 'one ')
        self.Append(popmenu)
        popmenu2 = wx.MenuItem(self, 10002, 'two')
        self.Append(popmenu2)

class MyPanel(wx.Panel):
    def __init__(self):
        super().__init__()
        self.Bind(wx.EVT_SHOW, self.OnShow)
        
    def OnShow(self, event):
        res = Ap.ResourceOverride()
        #import the XRC
        wx.ToolTip.Enable(True)
        self.res = xrc.XmlResource('./wxPaletteTab.xrc')
        self.childpanel = self.res.LoadPanel(self, "ID_WXPALETTETAB")
        if not self.childpanel:
             raise Exception("failed to find xrc file") 
        
        #create a sizer and add the child
        sizer = wx.BoxSizer(wx.VERTICAL)
        sizer.Add(self.childpanel,1,wx.ALL|wx.EXPAND)
        self.SetSizerAndFit(sizer)
        self.Layout()

        #get ctrls as member variables 
        self.comboctrl = xrc.XRCCTRL(self,'wxID_COMBOCTRL')
        self.textctrl = xrc.XRCCTRL(self,'wxID_TEXTCTRL')
        self.radioleftctrl = xrc.XRCCTRL(self,'wxID_RADIOBUTTON_LEFT')
        self.radiorightctrl = xrc.XRCCTRL(self,'wxID_RADIOBUTTON_RIGHT')
        self.button_1ctrl = xrc.XRCCTRL(self,'wxID_BUTTON_1')
        self.button_2ctrl = xrc.XRCCTRL(self,'wxID_BUTTON_2')
        self.listctrl = xrc.XRCCTRL(self,'wxID_LISTCTRL')
        
        self.index = 0
        self.OnInitListCtrl()

        #bind events
        self.Bind(wx.EVT_CHOICE,self.OnChoice,self.comboctrl)
        self.Bind(wx.EVT_CHAR_HOOK,self.OnEventChar, self.textctrl)
        self.Bind(wx.EVT_RADIOBUTTON,self.OnRadioLeft, self.radioleftctrl)
        self.Bind(wx.EVT_RADIOBUTTON,self.OnRadioRight, self.radiorightctrl)
        self.Bind(wx.EVT_BUTTON,self.OnButton_1, self.button_1ctrl)
        self.Bind(wx.EVT_BUTTON,self.OnButton_2, self.button_2ctrl)
        self.Bind(wx.EVT_LIST_BEGIN_DRAG,self.OnDragInit,self.listctrl)
        self.Bind(wx.EVT_CONTEXT_MENU, self.OnContextMenu, self.listctrl)
        self.Bind(wx.EVT_LIST_ITEM_SELECTED, self.OnItemSelected, self.listctrl)
        
    def OnInitListCtrl(self):
        self.listctrl.InsertColumn(0, 'Item',width=125)
        self.listctrl.InsertColumn(1, 'Date',width=125)
        
    def OnChoice(self, event):
        selection = self.comboctrl.GetSelection()
        selectionString = self.comboctrl.GetString(selection)
        print(selection,selectionString)
        
    def OnEventChar(self, event):
        keyCode = event.GetKeyCode() 
        character = chr(keyCode)
        print(keyCode,character)
        event.Skip()
        
    def OnButton_1(self, event):
        self.listctrl.InsertItem(self.index, self.textctrl.Value)
        self.listctrl.SetItem(self.index, 1, date.today().strftime("%d/%m/%Y"))
        self.index += 1
        
    def OnButton_2(self, event):
        print("button 2")
        
    def OnRadioLeft(self, event):
        print("OnRadioLeft")
        
    def OnRadioRight(self, event):
        print("OnRadioRight")
        
    def OnDragInit(self, event): 
        text = self.listctrl.GetItemText(event.GetIndex()) 
        tobj = wx.TextDataObject(text) 
        src = wx.DropSource(self.listctrl) 
        src.SetData(tobj) 
        print(src.DoDragDrop(True))
        
    def OnContextMenu(self,event):
        try:
            res = Ap.ResourceOverride()
            self.listctrl.PopupMenu(PopMenu(self), event.GetPosition())
        except Exception as err:
            print(err)
        event.Skip()
            
    def OnItemSelected(self,event):
        print("OnItemSelected")
    
    def OnClearAll(self,event):
        self.listctrl.ClearAll()
        
    def OnClick(self, event):
        print("OnClick")
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