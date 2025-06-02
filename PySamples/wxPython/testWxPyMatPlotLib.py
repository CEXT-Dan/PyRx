from pyrx import Rx, Ge, Gi, Db, Ap, Ed, Ax
import wx

# imports
import numpy as np
import matplotlib

# tell matplotlib to use wxPython
matplotlib.use("WXAgg")
from matplotlib.backends.backend_wxagg import FigureCanvasWxAgg as FigureCanvas
from matplotlib.figure import Figure

print("Added command = showplotlib")


def PyRxCmd_showplotlib():
    try:
        res = Ap.ResourceOverride()
        dlg = TestDialog(None, -1, "Plot", wx.Size(500, 400))
        if dlg.ShowModal() == wx.ID_OK:
            print("Yay!")
    except Exception as err:
        print(err)


# matplotlib panel as a control, with a custom draw
class CanvasPanel(wx.Panel):
    def __init__(self, parent):
        wx.Panel.__init__(self, parent)
        self.figure = Figure(figsize=(1, 1))
        self.axes = self.figure.add_subplot(111)
        self.canvas = FigureCanvas(self, -1, self.figure)
        self.sizer = wx.BoxSizer(wx.VERTICAL)
        self.sizer.Add(self.canvas, 1, wx.LEFT | wx.TOP | wx.GROW)
        self.SetSizerAndFit(self.sizer)

    # https://matplotlib.org/stable/gallery/images_contours_and_fields/contourf_hatching.html#contourf-hatching
    def draw(self):
        x = np.linspace(-3, 5, 150).reshape(1, -1)
        y = np.linspace(-3, 5, 120).reshape(-1, 1)
        z = np.cos(x) + np.sin(y)
        x, y = x.flatten(), y.flatten()
        cs = self.axes.contourf(
            x,
            y,
            z,
            hatches=["-", "/", "\\", "//"],
            cmap="gray",
            extend="both",
            alpha=0.5,
        )
        self.figure.colorbar(cs)


class TestDialog(wx.Dialog):
    def __init__(
        self,
        parent,
        id,
        title,
        size,
        pos=wx.DefaultPosition,
        style=wx.DEFAULT_DIALOG_STYLE,
    ):

        # init
        wx.Dialog.__init__(self)
        self.Create(parent, id, title, pos, size, style)
        self.pltpanel = CanvasPanel(self)
        self.Bind(wx.EVT_INIT_DIALOG, self.OnInitDialog)

        # create a sizer and append the controls
        sizer = wx.BoxSizer(wx.VERTICAL)
        sizer.SetMinSize(size)
        sizer.Add(self.pltpanel, 1, wx.LEFT | wx.TOP | wx.GROW)

        btnsizer = wx.StdDialogButtonSizer()
        if wx.Platform != "__WXMSW__":
            btn = wx.ContextHelpButton(self)
            btnsizer.AddButton(btn)

        # ok button
        btn = wx.Button(self, wx.ID_OK)
        btn.SetDefault()
        btnsizer.AddButton(btn)
        # cancel button
        btn = wx.Button(self, wx.ID_CANCEL)
        btnsizer.AddButton(btn)
        btnsizer.Realize()
        # add and resize
        sizer.Add(btnsizer, 0, wx.RIGHT | wx.BOTTOM | wx.GROW, 5)
        self.SetSizerAndFit(sizer)

    # show the world
    def OnInitDialog(self, event):
        Ap.Application.setTitleThemeDark(self.GetHandle())
        Ap.Application.applyHostIcon(self.GetHandle())
        self.pltpanel.draw()
