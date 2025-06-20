import win32api
import win32con
import win32gui
import wx
from wx import xrc

from pyrx import Ap, Ed

WM_ACAD_KEEPFOCUS = 28929


def OnPyInitApp():
    print("\nOnPyInitApp")
    print("Added command 'wxpyxrcm'")


def OnPyUnloadApp():
    print("\nOnPyUnloadApp")


def OnPyLoadDwg():
    print("\nOnPyLoadDwg")


def OnPyUnloadDwg():
    print("\nOnPyUnloadDwg")


# command to launch the dialog
def PyRxCmd_wxpyxrcm():
    try:
        dlg = TestDialog(None, -1, "")
        dlg.Show()
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

        self.getPointButton = xrc.XRCCTRL(self, "ID_BUTTON_GET_POINT")
        self.Bind(wx.EVT_BUTTON, self.onGetPoint, self.getPointButton)
        self.getPointButton.SetToolTip("Hello World")

        self.getDistButton = xrc.XRCCTRL(self, "ID_BUTTON_GET_DIST")
        self.Bind(wx.EVT_BUTTON, self.onGetDist, self.getDistButton)
        self.getDistButton.SetToolTip("Hello World")

        self.textPointResult = xrc.XRCCTRL(self, "ID_TEXTCTRL_POINT_RESULT")
        self.textDistResult = xrc.XRCCTRL(self, "ID_TEXTCTRL_DIST_RESULT")

        self.keepFocus = 1
        self.Bind(wx.EVT_CLOSE, self.OnClose)
        self.addHook()

    # we need this to capture WM_ACAD_KEEPFOCUS
    def addHook(self):
        self.oldWndProc = win32gui.SetWindowLong(
            self.GetHandle(), win32con.GWL_WNDPROC, self.MyWndProc
        )

    def restoreHook(self):
        wx.MessageBox("YAY")
        return win32api.SetWindowLong(self.GetHandle(), win32con.GWL_WNDPROC, self.oldWndProc)

    def OnClose(self, event):
        self.restoreHook()
        self.Destroy()

    def MyWndProc(self, hWnd, msg, wParam, lParam):
        if msg == WM_ACAD_KEEPFOCUS:
            return self.keepFocus
        elif msg == win32con.WM_DESTROY:
            self.restoreHook()
        return win32gui.CallWindowProc(self.oldWndProc, hWnd, msg, wParam, lParam)

    def onGetPoint(self, event):
        try:
            self.keepFocus = 0
            val = Ap.Application().docManager().curDocument().editor().getPoint("\nGetPoint\n")
            if val[0] == Ed.PromptStatus.eNormal:
                self.textPointResult.SetValue(val[1].__str__())
        finally:
            self.keepFocus = 1

    def onGetDist(self, event):
        try:
            self.keepFocus = 0
            val = Ap.Application().docManager().curDocument().editor().getDist("\nGetDist\n")
            if val[0] == Ed.PromptStatus.eNormal:
                self.textDistResult.SetValue(val[1].__str__())
        finally:
            self.keepFocus = 1
