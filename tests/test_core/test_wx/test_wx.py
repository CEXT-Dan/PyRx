from __future__ import annotations
from pyrx import Ap
import wx


class TestWxPython:

    def test_get_app(self):  # just test possible types
        pyapp: wx.App = Ap.Application.wxApp()
        topWin: wx.Window = pyapp.TopWindow
        assert topWin != None

    def test_get_hwnd(self):  # just test possible types
        pyapp: wx.App = Ap.Application.wxApp()
        topWin: wx.Window = pyapp.TopWindow
        assert topWin.Handle == Ap.Application.mainWnd()

    def test_get_wxapp(self):  # just test possible types
        pyapp: wx.App = wx.App.Get()
        topWin: wx.Window = pyapp.TopWindow
        assert topWin != None

    def test_get_wxhwnd(self):  # just test possible types
        pyapp: wx.App = wx.App.Get()
        topWin: wx.Window = pyapp.TopWindow
        assert topWin.Handle == Ap.Application.mainWnd()

    def test_get_wxappget(self):  # just test possible types
        pyapp: wx.App = wx.GetApp()
        topWin: wx.Window = pyapp.TopWindow
        assert topWin != None

    def test_get_wxhwndget(self):  # just test possible types
        pyapp: wx.App = wx.GetApp()
        topWin: wx.Window = pyapp.TopWindow
        assert topWin.Handle == Ap.Application.mainWnd()
