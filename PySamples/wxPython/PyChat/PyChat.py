import traceback
from threading import Thread

import wx
from meta_ai_api import MetaAI
from wx import xrc

from pyrx import Ap

print("added command PyChat")


class PalettePanel(wx.Panel):
    def __init__(self):
        super().__init__()
        self.Bind(wx.EVT_SHOW, self.OnShow)
        self.ai = MetaAI()

    # import the .XRC file and init the controls
    def OnShow(self, event):
        _res = Ap.ResourceOverride()
        wx.ToolTip.Enable(True)
        self.res = xrc.XmlResource("./PyChat.xrc")
        self.childpanel = self.res.LoadPanel(self, "wxID_CHATPANEL")
        if not self.childpanel:
            raise Exception("failed to find xrc file")

        # create a sizer and add the child
        sizer = wx.BoxSizer(wx.VERTICAL)
        sizer.Add(self.childpanel, 1, wx.ALL | wx.EXPAND)
        self.SetSizerAndFit(sizer)
        self.Layout()

        # get ctrls as member variables
        self.input: wx.TextCtrl = xrc.XRCCTRL(self, "wxID_TEXTCTRL_INPUT")
        self.output: wx.TextCtrl = xrc.XRCCTRL(self, "wxID_TEXTCTRL_OUTPUT")
        self.bsend: wx.Button = xrc.XRCCTRL(self, "wxID_BUTTON_SEND")

        # bind events
        self.Bind(wx.EVT_SIZE, self.OnSize)
        self.Bind(wx.EVT_BUTTON, self.OnSend, self.bsend)
        self.set_dark_mode(self)

    # some colors I thought were cool
    def set_dark_mode(self, control):
        bkclr = wx.Colour(pychatpalette.paletteBackgroundColor())
        fgcolor = wx.Colour(pychatpalette.paletteTabTextColor())
        for child in control.GetChildren():
            child.SetForegroundColour(fgcolor)
            child.SetBackgroundColour(bkclr)
            self.set_dark_mode(child)

    def OnSize(self, event):
        event.Skip()

    def doit(self):
        ai_result = self.ai.prompt(message=self.input.Value)
        self.output.Clear()
        self.output.SetValue(ai_result["message"])

    def OnSend(self, event):
        try:
            self.output.SetValue("waiting for response....")
            thread = Thread(target=self.doit)
            thread.start()
        except Exception as err:
            traceback.print_exception(err)


pychatpalette = Ap.PaletteSet("PyChat")


def createPalette() -> None:
    try:
        panel = PalettePanel()
        pychatpalette.add("ChatPanel", panel)
        pychatpalette.setVisible(True)
    except Exception as err:
        print(err)


def PyRxCmd_pychat() -> None:
    try:
        createPalette()
    except Exception as err:
        print(err)
