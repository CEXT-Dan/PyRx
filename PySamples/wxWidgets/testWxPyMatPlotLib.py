
from numpy import arange, sin, pi

import matplotlib
matplotlib.use('WXAgg')
from matplotlib.backends.backend_wxagg import FigureCanvasWxAgg as FigureCanvas
from matplotlib.figure import Figure

from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

import wx

print("Added command = showplotlib")

def PyRxCmd_showplotlib():
    try: 
        res = Ap.ResourceOverride()
        dlg = TestDialog(None, -1, "Plot",wx.Size(500,300))
        if dlg.ShowModal() == wx.ID_OK:
            print("Yay!")
    except Exception as err:
        print(err)

        
class CanvasPanel(wx.Panel):
    def __init__(self, parent):
        wx.Panel.__init__(self, parent)
        self.figure = Figure(figsize=(1,1))
        self.axes = self.figure.add_subplot(111)
        self.canvas = FigureCanvas(self, -1, self.figure)
        self.sizer = wx.BoxSizer(wx.VERTICAL)
        self.sizer.Add(self.canvas, 1, wx.LEFT | wx.TOP | wx.GROW)
        self.SetSizerAndFit(self.sizer)

    def draw(self):
        t = arange(0.0, 3.0, 0.01)
        s = sin(2 * pi * t)
        self.axes.plot(t, s)
        
class TestDialog(wx.Dialog):
    def __init__(
            self, parent, id, title, size, pos=wx.DefaultPosition,
            style=wx.DEFAULT_DIALOG_STYLE):

        wx.Dialog.__init__(self)
        self.Create(parent, id, title, pos, size, style)
        self.Bind(wx.EVT_INIT_DIALOG, self.OnInitDialog)
        

        self.pltpanel = CanvasPanel(self)
        
        sizer = wx.BoxSizer(wx.VERTICAL)
        sizer.SetMinSize(size)
        sizer.Add(self.pltpanel, 1, wx.LEFT | wx.TOP | wx.GROW)
        
        btnsizer = wx.StdDialogButtonSizer()

        if wx.Platform != "__WXMSW__":
            btn = wx.ContextHelpButton(self)
            btnsizer.AddButton(btn)

        btn = wx.Button(self, wx.ID_OK)
        btn.SetDefault()
        btnsizer.AddButton(btn)

        btn = wx.Button(self, wx.ID_CANCEL)
        btnsizer.AddButton(btn)
        btnsizer.Realize()

        sizer.Add(btnsizer, 0, wx.RIGHT | wx.BOTTOM| wx.GROW, 5)
        self.SetSizerAndFit(sizer)


    def OnInitDialog(self, event):
        Ap.Application.setTitleThemeDark(self.GetHandle())
        Ap.Application.applyHostIcon(self.GetHandle())
        self.pltpanel.draw()
   

        