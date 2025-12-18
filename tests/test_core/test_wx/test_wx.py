from __future__ import annotations

import wx

from wx import xrc
from pyrx import Ap

wx_CallAfter = 1

def wx_CallAfter_setval(val):
    global wx_CallAfter
    wx_CallAfter = val

def do_wx_CallAfter(val):
    wx.CallAfter(wx_CallAfter_setval, val)
    
do_wx_CallAfter(10)

class TestWxPython:
    def test_get_app(self):  # just test possible types
        pyapp: wx.App = Ap.Application.wxApp()
        assert isinstance(pyapp, wx.PyApp)
        topWin: wx.Window = pyapp.TopWindow
        assert topWin != None

    def test_get_hwnd(self):  # just test possible types
        pyapp: wx.App = Ap.Application.wxApp()
        assert isinstance(pyapp, wx.PyApp)
        topWin: wx.Window = pyapp.TopWindow
        assert topWin.Handle == Ap.Application.mainWnd()
        
    def test_get_xrc(self):  # just test possible types
        _xrc = xrc.XmlResource()
        assert _xrc != None
        
    def test_get_wxapp(self):  # just test possible types
        pyapp: wx.App = wx.App.Get()
        assert isinstance(pyapp, wx.PyApp)
        topWin: wx.Window = pyapp.TopWindow
        assert topWin != None

    def test_get_wxhwnd(self):  # just test possible types
        pyapp: wx.App = wx.App.Get()
        assert isinstance(pyapp, wx.PyApp)
        topWin: wx.Window = pyapp.TopWindow
        assert topWin.Handle == Ap.Application.mainWnd()

    def test_get_wxappget(self):  # just test possible types
        pyapp: wx.App = wx.GetApp()
        assert isinstance(pyapp, wx.PyApp)
        topWin: wx.Window = pyapp.TopWindow
        assert topWin != None

    def test_get_wxhwndget(self):  # just test possible types
        pyapp: wx.App = wx.GetApp()
        assert isinstance(pyapp, wx.PyApp)
        topWin: wx.Window = pyapp.TopWindow
        assert topWin.Handle == Ap.Application.mainWnd()
        
    def test_wx_CallAfter(self):  # just test possible types
        assert wx_CallAfter == 10

