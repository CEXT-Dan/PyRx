from __future__ import annotations
from pyrx import Ap
import wx


class TestWxPython:

    def test_get_wxapp(self):  # just test possible types
        pyapp: wx.App = Ap.Application.wxApp()
        topWin: wx.Window = pyapp.TopWindow
        assert topWin != None

    def test_get_hwnd(self):  # just test possible types
        pyapp: wx.App = Ap.Application.wxApp()
        topWin: wx.Window = pyapp.TopWindow
        assert topWin.Handle == Ap.Application.mainWnd()
