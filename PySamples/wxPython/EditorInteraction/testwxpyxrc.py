import wx
from wx import xrc

from pyrx import Ap, Ed

print("Added command 'wxpyxrc'")


# command to launch the dialog
def PyRxCmd_wxpyxrc():
    try:
        _resource = Ap.ResourceOverride()
        dlg = TestDialog(None, -1, "")
        # or dlg.ShowModal()
        # showModalDialog will set the icon
        res = Ap.Application.showModalDialog(dlg)
        if res == wx.ID_OK:
            print("woohoo")
        print(res)
    except Exception as err:
        print(err)


class TestDialog(wx.Dialog):
    def __init__(
        self,
        parent,
        id,
        title,
        size=wx.DefaultSize,
        pos=wx.DefaultPosition,
        style=wx.DEFAULT_DIALOG_STYLE,
        name="ID_SELECTTEST",
    ):
        wx.Dialog.__init__(self)
        self.res = xrc.XmlResource("./selectTest.xrc")
        if not self.res.LoadDialog(self, parent, "ID_SELECTTEST"):
            raise Exception("failed to find xrc file")

        self.getPointButton: wx.Button = xrc.XRCCTRL(self, "ID_BUTTON_GET_POINT")
        self.Bind(wx.EVT_BUTTON, self.onGetPoint, self.getPointButton)
        self.getPointButton.SetToolTip("Hello World")

        self.getDistButton = xrc.XRCCTRL(self, "ID_BUTTON_GET_DIST")
        self.Bind(wx.EVT_BUTTON, self.onGetDist, self.getDistButton)
        self.getDistButton.SetToolTip("Hello World")

        self.textPointResult = xrc.XRCCTRL(self, "ID_TEXTCTRL_POINT_RESULT")
        self.textDistResult = xrc.XRCCTRL(self, "ID_TEXTCTRL_DIST_RESULT")

    def onGetPoint(self, event):
        ps, pnt = Ed.Editor().getPoint("\nGetPoint: ")
        if ps == Ed.PromptStatus.eNormal:
            self.textPointResult.SetValue(pnt.__str__())

    def onGetDist(self, event):
        ps, dist = Ed.Editor.getDist("\nGetDist: ")
        if ps == Ed.PromptStatus.eNormal:
            self.textDistResult.SetValue(dist.__str__())
