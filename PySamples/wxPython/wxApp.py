import traceback
from pyrx import Rx, Ge, Gi, Db, Ap, Ed, Ax
import wx


# example of how to get an instance of wxApp
def PyRxCmd_doit():
    try:
        app: wx.App = Ap.Application.wxApp()
        print(app.AppName)
    except Exception as err:
        print(err)
