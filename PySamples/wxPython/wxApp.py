import wx

from pyrx import Ap


# example of how to get an instance of wxApp
def PyRxCmd_doit():
    try:
        app: wx.App = Ap.Application.wxApp()
        print(app.AppName)
    except Exception as err:
        print(err)
