
from numpy import arange, sin, pi

import matplotlib
matplotlib.use('WXAgg')
from matplotlib.backends.backend_wxagg import FigureCanvasWxAgg as FigureCanvas
from matplotlib.figure import Figure

import PyRxApp
import PyRx
import PyGe
import PyGi
import PyDb
import PyAp
import PyEd
import wx

def PyRxCmd_wxpy():
    try: 
        res = PyAp.ResourceOverride()
        dlg = TestDialog(None, -1, "Plot",wx.Size(700,700))
        if dlg.ShowModal() == wx.ID_OK:
            print(dlg.text1.GetValue())
            print(dlg.text2.GetValue())
    except Exception as err:
        PyRxApp.Printf(err)

        
class CanvasPanel(wx.Panel):
    def __init__(self, parent):
        wx.Panel.__init__(self, parent)
        self.figure = Figure()
        self.axes = self.figure.add_subplot(111)
        self.canvas = FigureCanvas(self, -1, self.figure)
        self.sizer = wx.BoxSizer(wx.VERTICAL)
        self.sizer.Add(self.canvas, 1, wx.LEFT | wx.TOP | wx.GROW)
        self.SetSizer(self.sizer)
        self.Fit()

    def draw(self):
        t = arange(0.0, 3.0, 0.01)
        s = sin(2 * pi * t)
        self.axes.plot(t, s)
   
class TestDialog(wx.Dialog):
    def __init__(
            self, parent, id, title, size, pos=wx.DefaultPosition,
            style=wx.DEFAULT_DIALOG_STYLE, name='dialog'
            ):

        wx.Dialog.__init__(self)
        self.SetExtraStyle(wx.DIALOG_EX_CONTEXTHELP)
        self.Create(parent, id, title, pos, size, style, name)
        PyAp.Application.setTitleThemeDark(self.GetHandle())
        
        self.pltpanel = CanvasPanel(self)
        self.pltpanel.draw()


        